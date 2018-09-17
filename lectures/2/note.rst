.. include:: ../../links.txt
.. include:: ../../roles.txt

.. _lec2:

.. contents:: Table of Contents
   :local:
   :depth: 1
   :backlinks: top

.. _lec2_ref:

Understanding References in `C++`_
==================================

.. contents::
   :local:
   :backlinks: top

A reference is an **alternative name** of another object in `C++`_. The syntax
is adding ``&`` after the type identifier (declarator), i.e.
:code:`[type] &var`.

Initializing Variables vs. Initializing References
--------------------------------------------------

In lecture 1 :ref:`lec1_define_init`, we have learned how to initialize a
variable, e.g.

.. code-block:: cpp

    int a = 1;  // define and initialize integer a with value 1

When we initialize a variable, the initializer (right-hand side) will be copied
to the variable. The above code is to copy the right-hand side, which is 1, to
variable ``a``. Intuitively, recopying values is allowed for variables, so that
you can write:

.. code-block:: cpp

    int a;  // define a
    a = 2;  // recopy value 2

However, for references, we bind, instead of copy, them to their initializers.
Each reference is bound to its initial object, and rebinding it is not allowed.

.. warning:: All references must be defined with initializers!

.. note:: A reference is just an alias of an object!

.. code-block:: cpp

    int obj = 1;        // integer of value 1
    int &ref = obj;     // bind reference ref to obj

For the code above, if we modify the value of :code:`obj`, say :code:`obj=2;`,
what will be the value of :code:`ref`?

Checkout :nblec_2:`ref` and run it.

.. note::

    Modifying a reference will affect the object that it bind to. Essentially,
    the behavior of an object and its references is synchronized.

Due to the fact that a reference can be used to modify the values of its
original object, **binding a (normal) reference to a constant object is not
allowed!**

.. code-block:: cpp

    const double tol = 1e-2;
    double &tol_ref = tol; // error!
    // similarly, a literal is considered to be constant object
    char &A = 'A'; // error!


References with :code:`const`-Qualifier
---------------------------------------

You can bind a constant object with **constant reference**. Because a reference
itself already has the property of :code:`const`-ness, i.e. you cannot rebind
a reference, **constant reference** can also be used to bind temporary
variables (future).

.. code-block:: cpp

    const float alpha = 1.0f;
    const float &alpha_ref = alpha;  // ok!
    const std::string &str_ref = "ams562"; // ok!

.. note:: You can bind constant references to normal objects.

Checkout and run :nblec_2:`const_ref`.

.. _lec2_ptr:

Understanding Pointers in `C++`_
================================

.. contents::
   :local:
   :backlinks: top

**Pointer** is probably one of the most difficult concept to understand in C
and `C++`_. Before we jump into pointers, we need to first understand the
memory addresses in `C++`_.

An **object** has its unique memory address. A pointer is a special type of
**objects** that can hold memory addresses as values.

To define a pointer, we need to add symbol :code:`*` after the type identifier,
i.e. :code:`[type] *ptr`.

The ``address-of`` operator
---------------------------

The ``dereference`` operator
----------------------------

.. _lec2_dyn:

Dynamic Memory Allocation/Deallocation
======================================

.. contents::
   :local:
   :backlinks: top

.. _lec2_def_list:

Defining a List of Variables
============================

.. contents::
   :local:
   :backlinks: top
