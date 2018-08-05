.. include:: ../links.txt
.. include:: ../roles.txt

.. _intro_why_cpp:

Why `C++`?
==========

.. contents:: Table of Contents
   :local:
   :backlinks: top


You Should Consider Using `C++` If
----------------------------------

The chances are that you may heard a lot of good things of `C++`, and finally
you have decided to give it a shot. Great! There is not doubt with the power of
`C++`. It is one of the most widely used programming languages, found in a
large range of applications. Unsurprisingly, `scientific computing` communities
use `C++` quite often in their projects. For instance, if you are interested in
solving `partial differential equations` (PDEs), then open-sourced frameworks
such as `OpenFOAM`_ and `SU2`_ might attract people who work in `computational
fluid dynamics` (CFD), and `FEniCS`_ and `deal.II`_ for researchers who are
interested in `finite element methods` (FEM) for solving, say, structural
problems. Of course, the `computational geometry algorithms library` (`CGAL`_)
is very popular for computer scientists who develop geometry-based algorithms.
What about for students who work in much lower level research areas, such as
developing numerical algorithms. No problem, `Eigen`_ has been around for
decades that supports efficient representations of fundamental numerical
computation objects, like vectors, matrices, and tensors. OK, I think I can
stop here!

Concepts that you learn from `C++` can be directly used in other programming
languages such as `Java`, `Python`_, `MATLAB`_, `C`, `Fortran`, etc.
Personally, I believe writing an algorithm in `C++` helps you fully understand
the idea and, potentially, can also improve the algorithm design. Let's say,
you probably has already learned how to do matrix multiplications in your
college linear algebra classes. Then, when your instructors asked you to
implement this as homework assignment in `MATLAB`_, what you did is probably
something like the following

.. code-block:: matlab

  A = rand(3);
  B = rand(3);
  C = A*B;

or in `Python`_

.. code-block:: python

  import numpy as np
  A = np.random.random((3,3))
  B = np.random.random((3,3))
  C = A.dot(B)

Well, I am kidding! This is cheating as homework assignments. You probably
implemented the triple for-loops. If you did a timing analysis, you would probably
see that the triple for-loop version is more than 100 times slower. Languages like
`Python`_ or `MATLAB`_ hide details from users, for instance, many students
don't understand how matrices are stored in `MATLAB`_ and `NumPY` and the
difference between accessing from column ``j`` to column ``j+1`` in these two
languages, i.e. speed is different when accessing :python:`A[i,j:j+2]` and
:matlab:`A(i,j:j+1)`. On the other side, `C++` hides nothing from users.

You Should **NOT** Consider Using `C++` If
------------------------------------------

`Very well, so I should only code with C++!` Wait, wait...
