.. include:: ../../links.txt
.. include:: ../../roles.txt

.. _lec4:

.. contents:: Table of Contents
   :local:
   :depth: 1
   :backlinks: top

.. _lec4_func_basis:

The Basis
=========

.. contents::
   :local:
   :backlinks: top

*Function* is an important concept in programming, because it allows us to
easily modularize our programs and reuse the codes in the future. In this
lecture, I will show you how to write functions in `C++`_.

Fundamental Concepts of Functions in `C++`_
-------------------------------------------

Currently, we write everything inside the :ref:`main <intro_simple_cpp_main>`
function. This is fine for small projects, say homework assignments. However,
for larger projects, this can be very limited. Consider the following
situation.

.. code-block:: cpp

    int flag;
    std::string method;
    // do something with flag
    flag = ...;
    switch (flag) {
    case 0:
        method = "method1";
        break; // don't forget break the switch
    case 1:
        method = "method2";
        break;
    case 2:
        method = "method3";
        break;
    default:
        method = "default";
        break;
    }

    // then run different statements with different "methods"


This code looks fine, but assume you need to determine the "method" twice in
your program, then the intuitive solution would be: "okay, let's just copy
and paste this part." This, of course, works, but what about later on, you need
to add another method, say "method4". You need to add "method4" twice, otherwise
your program may run into troubles.

At this moment, you probably already notice the limitation of this approach,
i.e. not extendable and easy to introduce bugs. A right way is to use a
function:

.. code-block:: cpp
    :linenos:

    std::string chooseMethods(int flag) {
        std::method;
        switch (flag) {
        case 0:
            method = "method1";
            break; // don't forget break the switch
        case 1:
            method = "method2";
            break;
        case 2:
            method = "method3";
            break;
        default:
            method = "default";
            break;
        }
        return method;
    }

Now, in your program, whenever you need to determine the "method", you can
simply **call** the function ``chooseMethods``:

.. code-block:: cpp

    int flag;
    std::cout << "enter method flag integer: ";
    std::cin >> flag;
    std::string method = chooseMethods(flag);

In this way, everytime when you need to add a new method, there is only
once place you need to worry about, i.e. the function ``chooseMethods``.

Now, let's take a closer look at the function above, in which ``chooseMethods``
is its *name*, :code:`std::string` is the *return type*, and :code:`int flag`
is the *parameter list*.

.. tip:: Functions are objects.

Essentially, every function has:

1. a name,
2. a return type, and
3. a parameter list.

.. _lec4_func_empty_return:

Be aware that both 2 and 3 can be empty argument, i.e. ``void`` for empty
return and empty parameter list for the latter.

.. code-block:: cpp

    // an empty param list with empty return
    void printHelloWorld() {
        std::cout << "Hello World\n";
    }

Be aware that *empty value return* doesn't mean there is no return in the
function. The code above is equivalent to:

.. code-block:: cpp
    :emphasize-lines: 3

    void printHelloWorld() {
        std::cout << "Hello World\n";
        return;
    }

The emphasized line demonstrates that this function returns *empty value*.
Returning empty value is not necessary, but sometimes it can be useful.

.. code-block:: cpp

    void doWork(double *data) {
        *data = 1.0;
    }

For the ``doWork`` function, you can simply use it like:

.. code-block:: cpp

    double a;
    doWork(&a); // recall address-of operator to get the pointer
    std::cout << "a=" << a << ".\n"; // print 1

However, we know that if ``data`` is ``nullptr``, then we have a big problem,
i.e. recall dereferencing ``nullptr`` will cause ``seg fault``.

In this case, you can do a *quick return* by checking ``data``, and this
requires returning empty stage.

.. code-block:: cpp

    void doWork(double *data) {
        if (!data) {
            return;
        }
        *data = 1.0;
    }

The Return Type
+++++++++++++++

The return type of a function must be listed explicitly and uniquely, i.e.
you cannot have a function that has multiple return types.

.. code-block:: cpp

    int myFunc() { return 1; } // Ok
    // int, int want2Return2Ints() { return 1, 2; } // ERROR!

However, there are always workarounds to mimic multiple returns that appear
in dynamic languages, e.g. `Python`_. One of them is to use a
:ref:`struct <lec3_stm_loop_struct>`.

.. code-block:: cpp

    struct ComplexNumber {
        double real;
        double imag;
    }; // don't forget the semicolon

    ComplexNumber getDefaultComplexNumber() {
        ComplexNumber a;
        a.real = 0.0;
        a.imag = 0.0;
        return a;
    }

Nonempty return types can be handles or omitted.

.. code-block:: cpp

    bool assign(const int len, double *array, const double value) {
        if (!array || len < 0) {
            return false;
        }
        for (int i = 0; i < len; ++i) {
            array[i] = value;
        }
        return true;
    }

You can use the function above either

.. code-block:: cpp

    if (!assign(len, array, value)) {
        // recall that you should use cerr for error streaming
        // if the inputs are not acceptable, then we know that array is not
        // been touched
        std::cerr << "invalid inputs\n";
    }

or, simply do

.. code-block:: cpp

    assign(len, array, value);


The Parameter List
++++++++++++++++++

The :code:`(int flag)` in ``chooseMethods`` and :code:`(double *data)` in
``doWork`` are called parameter lists. In general, the parameter list of
functions is a *comma-separated* *declaration-like* of parameters. Therefore,
for a parameter list, multiple arguments are, of course, supported.

.. code-block:: cpp

    void demoParList(int a, double b, std::string method, double *data) {
        // do work
    }

.. note::

    The `C++`_ function parameter lists have strict order, i.e. there is
    not *key value pairs* in `C++`_ regarding function inputs.

Return Pointers & References
++++++++++++++++++++++++++++

There is nothing to stop you from returning :ref:`pointers <lec2_ptr>` and
:ref:`references <lec2_ref>`. However, whenever you directly access the memory,
special care must be taken.

Let's first look at the following function that returns a pointer:

.. code-block:: cpp

    int *getPointer() {
        int a = 1;
        int *ptr = &a;
        return ptr;
    }

On return, ``getPointer`` will return a **copy** of ``ptr`` and this behavior
is will defined. Now, let's look at the the *function body* (content inside
the function scope). A **local** integer ``a`` is created as well as a pointer
``ptr`` that points to it. The memory address of ``a`` is copied whiling
returning ``ptr``, but ``a`` is popped out from the stack right after the
return statement. **Therefore, the dereference of the returned pointer is
undefined.**

Typically, returning pointers is used for
:ref:`dynamic memory allocation <lec2_dyn>`:

.. code-block:: cpp

    double *allocArray(unsigned int size) {
        return new double [size];
    }

.. note:: Don't forget to relax the memory.

.. tip::

    If you need to write a function that returns a pointer pointing to
    the head memory, it's general practice that the function name should start
    with ``create``, ``alloc``, etc.

Returning references, on the other hand, is even tricker.

.. code-block:: cpp

    int &getRef() {
        int a;
        return a;
    }

The code above has the legal `C++`_ syntax. However, the returned reference
refers to some local variable that is gone once the function scope ends.
As a result, the refer you get from this function is undefined.

.. note::

    Typically, compilers will warn you for returning local references.

.. note::

    For new `C++`_ programmers, avoid returning references.

Forward Linked List, again, with Functions
++++++++++++++++++++++++++++++++++++++++++

Now, a more structured implementation of our
:ref:`forward linked list example <lec3_stm_loop_struct>` can be found in
:nblec_4:`func_fll`.

Passing Arguments
-----------------

Function Prototypes & Implementations
--------------------------------------
