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
is adding symbol ``&`` after the type identifier (declarator), i.e.
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
**objects** that can hold memory addresses as its values.

To define a pointer, we need to add symbol :code:`*` after the type identifier,
i.e. :code:`[type] *ptr`.

.. code-block:: cpp

    int *ptr;   // define a pointer

The ``address-of`` Operator
---------------------------

To extract the memory address of an object, we need to use the ``address-of``
operator, i.e. :code:`&`.

.. note::

    Do not get confused with the **symbol** :code:`&` used in defining
    :ref:`references <lec2_ref>`, since it appears after the **type**
    identifier. The ``address-of`` operator is used in front of **variables**.

.. code-block:: cpp
    :linenos:

    int a = 1;          // define an integer
    int *a_ptr = &a;    // define a pointer that points to a's address

In line 2, the ``address-of`` operator is used in order to extract the memory
address of ``a``, and the value (of the memory address) is assigned to the
pointer ``a_ptr``. Moreover, ``a_ptr`` is defined as a pointer that points an
integer object, typically, you cannot mix the pointer type and object type.

.. warning:: :code:`double *ptr = &a` is not allowed with the code above!

The ``dereference`` Operator
----------------------------

Accessing objects is a typical usage of pointers. To do so, we need the
``dereference`` operator---:code:`*`.

.. note::

    Similarly, do not confuse with ``dereference`` operator and the symbol
    :code:`*` for defining pointers.

.. code-block:: cpp

    int a = 1;
    int *a_ptr = &a;  // copy a's address
    std::cout << a_ptr << '\n'; // print a's address
    std::cout << a << "==" << *a_ptr << '\n';
    *a_ptr = 2;
    // what is a?

Checkout and run :nblec_2:`ptr`.

Initialize Pointers
-------------------

A **null pointer** points to a special memory address that indicates empty
object. Typically, you should initialize a pointer with **null** if you don't
know what addresses it needs to take. In `C++`_, we can use (and should use)
``nullptr`` for **null pointer**. Some programs prefer to use ``0`` and the
traditional ``NULL`` (from C, requiring ``<cstdlib>`` interface).

.. code-block:: cpp

    double *ptr1 = nullptr;  // C++ preferred
    double *ptr2 = 0;        // equiv way
    double *ptr3 = NULL;     // require <cstdlib>

.. warning::

    It is legal to **initialize** a pointer with value ``0`` (null). However,
    you cannot reset a pointer with integer object with value zero.

.. code-block:: cpp

    double *ptr = 0;    // fine!
    ptr = 0;            // ok!
    int zero = 0;
    ptr = zero;         // ERROR! cannot assign double * with int

.. tip:: Always use :code:`nullptr` in `C++`_.

.. warning::

    Uninitialized pointers are extremely dangerous and using them is one of
    the typical error sources.

.. code-block:: cpp

    int *p1;            // uninitialized
    int *p2 =nullptr;   // initialized but points to null
    int a;
    int *p3 = &a;

.. danger::

    You cannot deference ``nullptr``, since it will cause
    ``segmentation fault``, which is a critical memory bug that will
    immediately abort your programs.

.. code-block:: cpp

    int *a = nullptr;
    *a = 1;  // Seg fault! program crushes!!

References vs. Pointers
-----------------------

There are some similarities between :ref:`references <lec2_ref>` and pointers.
An obvious one is that you can use both to access and modify an object.

.. code-block:: cpp

    double tol = 1e-6;
    double &tol_ref = tol;
    double *tol_ptr = &tol;

    tol_ref = 1e-2;
    std::cout << tol << std::endl; // what is the output?
    std::cout << *tol_ptr << std::endl; // what about this?
    *tol_ptr = 0.0;
    std::cout << tol_ref << std::endl; // this?

However, there is one fundamental difference: **references are not an object!**
This means that you cannot get the memory addresses of references (well,
technically the memory address of a reference is that of the object it refers
to, since a reference is just an alias of an object.)

A pointer, on the other hand, is an object in `C++`_ thus having its own memory
address. You can also refer to pointers through the reference semantic.

.. code-block:: cpp

    int a;
    int b;
    int *p = &a;    // p holds a's addr
    int *&p_ref = p; // a reference of pointer
    p_ref = &b;     // what is p now?

    // similarly, since p is object, we can create pointers
    // that point to it
    int **pp = &p;  // pp holds p's address
    std::cout << *pp << '\n'; // what is the deref of pp
    *pp = &a;
    // what is p_ref now?

Try the :nblec_2:`ptr_ref`.

Pointers with :code:`const`-Qualifier
-------------------------------------

Unlike :ref:`references <lec2_ref>`, pointers are normal objects, so there is
a difference between *pointers to constants* and *constant pointers*.

.. _lec2_ptr_p2c:

A pointer to constant is that the pointer itself is a normal object but points
to a constant object, i.e. you cannot modify the underlying object. However,
you can modify the pointer, e.g. assign another memory address.

.. code-block:: cpp

    const int a = 1;
    const int *p2c = &a;
    *p2c = 2;   // ERROR! a is constant
    p2c = nullptr; // fine

.. _lec2_ptr_cp:

A constant pointer is that the pointer itself is constant object, i.e. you
cannot modify the memory address. But you can still dereference it to modify
the object that it points to.

.. code-block:: cpp

    int a;
    int *const p = &a; // you must initialize p, why?
    *p = 1; // fine
    p = nullptr; // ERROR!

Of course, you can have *constant pointers to constant*, i.e.

.. code-block:: cpp

    int a;
    const int *const p = &a;

    *p = 2; // ERROR!
    p = nullptr; // ERROR!

.. tip:: Read a declaration from right to left.

.. note:: Pointers to constant are widely used in practice.

.. _lec2_dyn:

Dynamic Memory Allocation/Deallocation
======================================

.. contents::
   :local:
   :backlinks: top

Stack Memory vs. Heap Memory
----------------------------

The stack memory is fast but limited. In general, the stack is fixed. Ideally,
we want to use the stack memory, because it is directly accessible to the CPU
stack registers and the operating system can even directly allocate the stack
in the cache. The fact is that all variables are constructed in the stack
memory.

.. note:: All arrays are stored in the stack.

However, due to the limited size, we can easily get ourselves into overflow.

.. code-block:: cpp

    double huge_data[extremely_large_size]; // this will break!

An easier way to understand this limitation is to look at the following
*recursive function*:

.. code-block:: cpp

    void never_call(int i) {
        int j = 1;
        int k = i;
        std::cout << k << std::endl;
        never_call(j+k); // recursively call "myself"
    }

Each time, when the function :code:`never_call` is invoked, three variables
will be created---``i`` (local copy), ``j`` and ``k``. Due to the recursive
mechanism, all the variables will live in the stack thus resulting
``segmentation fault`` eventually because of stack size overflow.

The **heap memory**, on the other side, is, loosely speaking, the left-over
memory in the RAM after 1) your program is loaded and 2) the memory is
allocated. Unlike the stack memory, where all variables are stored, the space
we request in the heap is not directly appeared in the program, we need to
create a :ref:`pointer <lec2_ptr>` that points to the leading (usually)
memory address of that chuck of memory space.

.. note::

    We typically refer variables that created in the stack as the *meta data*
    that describes the actual data, which is typically large and stored in the
    heap.

The heap memory is used for *dynamic memory allocation* (a.k.a runtime memory
allocation), which is usually used in the following two situations:

1. the data size is large, and
2. the data size is unknown and dynamically changing.

For the second one, a typical situation is that we you write a word processing
program, you don't know how many characters the user may use, so a memory
space that can grow dynamically is must.

.. tip::

    For some applications, even though the data size cannot be determined
    beforehand, but the upper bound can be precisely estimated. In this case,
    if the upper bound is small, then you should use the stack memory!
    One example would be create a :ref:`C-string <lec1_cstr>` to store
    the user input filename, i.e. :code:`char filename_buffer[200]`.

.. _lec2_dyn_new:

Dynamic Memory Allocation
-------------------------

Since we already learned that we need to use :ref:`pointers <lec2_ptr>` to
point to the memory locations in the head, you should not be surprised that
dynamic memory allocations involve using pointers. The syntax is
:code:`[type] *ptr = new [type]`, where the operator ``new`` is to allocate
memory dynamically.

.. code-block:: cpp

    int *bad_ptr = 3; // ERROR!
    int *ptr = new ptr;  // request a valid place first
    *ptr = 3;   // dereferencing a valid pointer is fine
    // or
    int *ptr_init = new int (3);

Dynamic Memory Deallocation
---------------------------

As we already learned in the :ref:`scope <lec1_scope>`, all variables have
the lifetime that is bounded by the scope, i.e.

.. code-block:: cpp

    {   // scope begins
        int a; // push a into the stack
    }   // scope ends, a is popped

Does this rule applied for dynamic memory in the heap? Recall that a
:ref:`lec2_ptr` is also a variable.

.. code-block:: cpp
    :linenos:

    {   // scope begins
        int *ptr = new int;  // allocate a dynamic chuck
    }   // scope ends, ptr is popped

In line 3, once the scope ends, ``ptr`` will be popped out and no long visible,
what about the dynamic memory it used to point at?

.. warning:: Dynamic memory will not be automatically cleaned up!

Actually, the code above is extremely dangerous, because once :code:`ptr`
is popped out, it's impossible for you to access to the dynamic memory space
that ``ptr`` used to point at. People refer this as *memory leaks*.

To relax a dynamic allocation, we need the deallocation operator ``delete``,
the syntax is :code:`delete [ptr];`.

.. code-block:: cpp

    {
        int * ptr = new int;
        delete ptr;  // freed here!
    }   // no leak!

.. important::

    There must be exactly a ``delete`` that matches to a ``new``.

.. code-block:: cpp

    double *p = new double;  // allocate here
    p = new double;     // reallocate here, previous allocation leaked!
    delete p;   // the first double is leaked.
    // delete p; // delete twice won't work and dangerous!

Dynamic Array Allocation/Deallocation
-------------------------------------

A common use of dynamic memory allocation is to request a large chunk of
contiguous memory space, i.e. an array, during runtime. For this task, should
use operator :code:`new[]` and relax the dynamic array with operator
:code:`delete[]`.

.. code-block:: cpp

    double *data;       // create the meta data
    unsigned long HUGE = ...;
    data = new double [HUGE]; // request the dynamic array of size HUGE
    // do work with data
    // don't forget to relax the memory
    delete[] data;

.. note::

    A :ref:`pointer <lec2_ptr>` can be accessed like an
    :ref:`array <lec1_array>` using operator :code:`[]`. For instance, given
    the example above, you can do :code:`data[0]` to access the first element
    in the dynamic array, and :code:`data[n]` for the n-th one.

A common mistake is mixing :code:`new/new[]` with :code:`delete/delete[]`.

.. warning::

    :code:`new` must be coupled with :code:`delete`, and the same rule applies
    for :code:`new[]` and :code:`delete[]`.

.. code-block:: cpp

    int *p1 = new int;
    delete [] p1; // WRONG!
    double *p2 = new double [2];
    delete p2; // WRONG!

Try the :nblec_2:`dyn`.

.. note::

    With modern `C++`_, you really don't need to worry that much about managing
    dynamic memory. In the future lectures, we will learn using ``vector`` as
    well as the so-called *smart pointers*.

.. _lec2_def_list:

Defining Multiple Variables
===========================

.. contents::
   :local:
   :backlinks: top

Now, with the knowledge of compound types, i.e. :ref:`pointers <lec2_ptr>` and
:ref:`references <lec2_ref>`, I think it's a good time for you to understand
a tricky part in `C++`_---defining multiple variables.

You can define multiple variables like:

.. code-block:: cpp

    int i, j;  // define two variables without initialization
    int k=0, t; // define another two, initialize k
    float x, y=1.0f; // only initialize the second one
    std::string depart("ams"), course("562"); // initialize both

This is pretty intuitive. Now let's say I want create two points:

.. code-block:: cpp

    int *ptr1, ptr2;
    ptr2 = nullptr; // ERROR!!

This is because compound types have the local property. Therefore, ``ptr2`` is
actually just an integer.

Now, try to figure out the types of the following variables.

.. code-block:: cpp

    int a=0,*b=0,&c=a,**d=&b,&e=c,**&f=d,g=e; // read from right to left
