.. include:: ../../links.txt
.. include:: ../../roles.txt

.. _lec10:

.. contents:: Table of Contents
   :local:
   :depth: 1
   :backlinks: top

Efficient Matrix Storage
=========================

.. contents::
   :local:
   :backlinks: top

In this lecture, we try to address a problem we have already "learned" how to
deal with---*how to store matrices?*

Previously, we learned that we can use a "double pointers" to store matrices,
since the double-pointer data structure can be natively mapped to any matrices.

.. code-block:: cpp

    double **mat;
    std::cout << "enter the number of row and columns [space separated]: ";
    unsigned m, n;
    std::cin >> m >> n;
    // first allocate m "rows"
    mat = new double *[m];
    // for each of the row, allocate n columns
    for (unsigned i = 0u; i < m; ++i)
        mat[i] = new double [n];
    // to access, using nested []
    mat[0][0] = 1.0;
    // we need to relax the memory
    for (unsigned i = 0u; i < m; ++i)
        delete [] mat[i];
    // delete the mat
    delete [] mat;

This is ugly and we need to manage the dynamic allocation explicitly. With
:ref:`vector <lec8>` from STL, we can use a nested :code:`std::vector`.

.. code-block:: cpp

    std::cout << "enter the number of row and columns [space separated]: ";
    unsigned m, n;
    std::cin >> m >> n;
    std::vector<std::vector<double>> mat(m, std::vector<double>(n));
    // explaination:
    //  we first allocate the outer vector with size m and unifrom
    //  value (std::vector<double>) of std::vector<double>(n)
    //  the value is another vector that is initialized with size n

But, is this enough? Obviously, the performance won't be good due to the
non-contiguous memory layout, i.e. the last element in row i and the first
element in row i+1 are not adjacent with each other. For relatively small
matrices, the penalty can be amplified.

How to Store Matrice Efficiently?
---------------------------------

Since we want to use compact storage, 1D arrays should be used instead of
"2D" ones. Also, each matrix has a row size and a column size, which can
be considered as shape descriptor; the actual matrix lies on top of a 1D
array that is virtually splitted into m rows and n columns by the shape
descriptor.

.. code-block:: cpp

    struct Matrix {
    std::vector<double> data;
    int rows, cols;
    };

Therefore, the array ``data`` has size of :code:`rows*cols`. Now, the question
is how to stretch the matrix into a 1D array, particularly speaking, given the
following matrix :math:`\boldsymbol{A}`, in what order we put the values into
``data``?

.. math::

    \boldsymbol{A}=
    \begin{pmatrix}
        1 & 2\\
        3 & 4
    \end{pmatrix}

``data`` can be either :code:`{1, 2, 3, 4}` or :code:`{1, 3, 2, 4}`.

C Order/Orientation
+++++++++++++++++++

In computational linear algebra, C order means that a matrix is stored with
with **row** orientation, i.e. ``data`` is :code:`[row0 row1 row2 ...]`.
For instance, given the matrix :math:`\boldsymbol{A}` above, the C order is
:code:`{1,2,3,4}`.

Fortran Order/Orientation
+++++++++++++++++++++++++

In contrast to C order, Fortran order stores matrices with column orientation,
e.g. :code:`data={1,3,2,4}`. That is, ``data`` is :code:`[col0 col1 col2 ...]`.

.. note::

    Column orientation is pretty standard in scientific programming due to the
    use of Fortran programming language. But for this class, we will focus on
    C order.

.. note::

    `MATLAB`_ stores matrices in Fortran order. NumPy allows you to choose between
    C and Fortran, but the default is in C order.

Leading Dimension and Submatrices
+++++++++++++++++++++++++++++++++

With ``data``, row size (``m``) and column size (``n``), let's see how to loop
through all entries in the matrix (assuming C order).

.. code-block:: cpp

    // the following code print the matrix
    // in the terminal with 2D shape
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            std::cout << mat[i*n+j] << ' ';
        std::cout << '\n'; // cut new line
    }

The key is ``i*n``, which gives you the starting index of row i.

Now, let's see how to deal with submatrices. One way is to create a whole copy
of the submatrices, but this approach is inefficient, because you need to
first allocate buffer, then copy the values, and most likely you need to push
the values back the original matrices once you are done with manipulating
the submatrices.

The problem can be solved by introducing the so-called *leading dimensions*.

.. note::

    A *leading dimension* of a matrix **memory** storage (assuming row orientation)
    is the stride size that equals to the difference between two adjacent entries
    in any column vectors.

.. math::

    \begin{pmatrix}
        1 & 2 & 3\\
        4 & 5 & 6
    \end{pmatrix}

Given the 2 by 3 matrix above, the leading dimension is 3 (column size).

.. tip::

    For **complete** row major (rwo orientated) matrices, their leading dimensions
    are just the corresponding column sizes.

With the leading dimension introduced, you can create submatrix descriptors instead
of memory copies. For instance, I want manipulate the submatrix:

.. math::

    \begin{pmatrix}
        2 & 3\\
        5 & 6
    \end{pmatrix}

i.e. the tailing 2 by 2 block, one way is:

.. code-block:: cpp

    std::vector<double> submat(4);
    submat[0] = mat[1]; // copy (0,1)
    submat[1] = mat[2]; // copy (0,2)
    submat[2] = mat[4]; // copy(1,1) 1*3+1
    submat[3] = mat[5]; // copy (1,2) 1*3+2
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            submat[i*2+j] *= (i+j);
    // copy back
    mat[1] = submat[0];
    mat[2] = submat[1];
    mat[4] = submat[2];
    mat[5] = submat[3];

Of course, this is inefficient, in stead, we can do:

.. code-block:: cpp

    double *submat = &mat[0*3+1]; // point to the (0,1)
    int ld = 3; // leading dimension
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            submat[i*ld+j] *= (i+j);
    // done!

Notice that ``submat`` points at the value 2 in the original matrix, which
has the leading dimension of 3. Then :code:`submat[ld]` is nothing but the
original position below 2, which is 5.

.. note::

    `BLAS <http://www.netlib.org/blas/>`_ (Basic Linear Algebra Subroutines and
    `LAPACK <http://www.netlib.org/lapack/>`_ (Linear Algebra PACKage) are
    next step you should look into. Particularly speaking, their C interfaces,
    *cblas* and *LAPACKE*.
