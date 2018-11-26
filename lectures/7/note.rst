.. include:: ../../links.txt
.. include:: ../../roles.txt

.. _lec7:

.. contents:: Table of Contents
   :local:
   :depth: 1
   :backlinks: top

Introduction to ``template`` & *STL*
====================================

What are Templates?
-------------------

`template` is a unique concept of `C++`_; it allows to define certain templates
for the compiler so that the latter can generate the code for you on the fly.
Using template enables the ability of interacting with compiler in order to
fully optimize the code.

A `template` argument can be either a **type** or an
:ref:`integral object <lec1_builtin_int>`. It can be applied to both functions
and classes.

Using templates is just like defining functions, you need to provide a list
of *template arguments* with in angle brackets, i.e. ``<>``.

.. code-block:: cpp

    template<class T>
    void print(const T& obj) {
        std::cout << obj;
    }

The function above defines a template function that simply writes the unique
input argument, ``obj``, into ``cout`` streamer.

The "type" ``T`` is a template or placeholder that will be deduced by the
compiler during compilation. For instance, we can directly plugin any
:ref:`build-in types <lec1_builtin>` into the ``print`` function, because
we know the output operator is well-defined for them.

.. code-block:: cpp

    print(1);       // int
    print(2.0);     // double
    print(3.0f);    // float
    print(1L);      // long

During instantiation of the template types, the compiler *must* compile the
code on the fly, which guarantees a better performance.

**Question**, do the print statements above refer to the same function?

**NO**, each of them is derived from the template function ``print`` and then
customized with the specific type ``T``. In fact, the actual function types
are:

.. code-block:: cpp

    print<int>(1);
    print<double>(2.0);
    print<float>(3.0f);
    print<long>(1L);

So, the actual :ref:`function type <lec4_func_adv_type>` of the first print is
:code:`void(int)` with function name :code:`print<int>`.

Now, for user defined types, i.e. classes, as long as the
:ref:`output operator is overloaded <lec6_adv_class_io>`, we can directly
plug them in without any addition efforts. For instance, our
:ref:`complex number <lec6_adv_class_cmplx>` is a perfect example.

.. code-block:: cpp

    ComplexNumber a(1.0, 2.0);
    print(a);

because the output operator is overloaded for ``ComplexNumber``, the function
:code:`print<ComplexNumber>` just works out-of-box.

.. note::

    Templates are one of the most useful and powerful technique in practice.
    However, due to its complexity and the time limitation of this class, it's
    impossible to cover it in detail. For further reading, I recommend
    the book `C++ Templates - The Complete Guide, 2nd Edition <http://www.tmplbook.com/>`_
    as a wonderful offline learning material.

.. tip::

    Essentially, the existence of ``template`` can be viewed as two kinds of
    restaurants; the first one provides a menu of dishes, whereas the second
    one provides a list of template recipes with the ingredients and seasonings
    offered by the customers.

The *Standard Template Libraries* (STL)
---------------------------------------

One of the s
