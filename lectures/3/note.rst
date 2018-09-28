.. include:: ../../links.txt
.. include:: ../../roles.txt

.. _lec3:

.. contents:: Table of Contents
   :local:
   :depth: 1
   :backlinks: top

.. _lec3_ops:

Operators & Operations
======================

.. contents::
   :local:
   :backlinks: top

.. _lec3_arith_ops:

Elementary Arithmetic Operators
-------------------------------

For most :ref:`built-in types <lec1_builtin>`, we have elementary operations
such as *addition*, *subtraction*, *multiplication*, *division*, and *modulus*.

1. :code:`+`: the addition operator
2. :code:`-`: the subtraction operator
3. :code:`*`: the multiplication operator
4. :code:`/`: the division operator
5. :code:`%`: the modulus operator

.. note::

    1 and 2 can be also used as unary operators, i.e. represent *positive* and
    *negative*, respectively.

Be aware that the modulus operator only works for integers in `C++`_, this is
unlike `Python`_, where the operator is also applicable to floating numbers.

.. code-block:: cpp

    int a = 5;
    std::cout << "mod(5,2)=" << 5%2;

    // std::cout << 5.0%2; // ERROR! % is not defined for floating numbers

Also, for the division operator, the behaviors for integers and floating
numbers are different.

.. code-block:: cpp

    std::cout << "5/2=" << 5/2; // this is 2
    std::cout << "5.0/2=" << 5./2; // this is 2.5

The resulting integers from dividing integers will be truncated. This is called
*integer division*.

.. note::

    The division is treated as *integer division* iff both left- and right-hand
    sides are integer types.

.. _lec3_assign_ops:

Assignment Operators
--------------------

So far, we have frequently been using the assignment operator, i.e. :code:`=`.
There are other types of assignment operators in `C++`_.

1. :code:`+=`: plus assignment
2. :code:`-=`: minus assignment
3. :code:`*=`: product assignment
4. :code:`/=`: quotient assignment
5. :code:`%=`: remainder assignment

There are so-called *compound assignment operators*, and you under these by the
following expression: :code:`A?=B` for :code:`?` :math:`\in`
:code:`{+,-,*,/,%}` is equivalent to :code:`A=A?B`.

.. _lec3_inc_dec_ops:

Increment & Decrement Operators
-------------------------------

In `C++`_, we also have increment and decrement operators for integers to
increase or decrease their values by 1.

1. :code:`++`: increment operator
2. :code:`--`: decrement operator

Use as Suffix
+++++++++++++

These operators can be used as suffixes, e.g.

.. code-block:: cpp

    int a = 0;
    a++;
    std::cout << a; // print out 1

**Post- increment/decrement operators modify the value of the target object
after processing the current statement.**

.. code-block:: cpp

    int a = 0;
    int b = a++;
    std::cout << "a=" << a;
    std::cout << "b=" << b;
    // what is a? what is b? try this!


Use as Prefix
+++++++++++++

These operators, of course, can be used as prefixes, e.g.

.. code-block:: cpp

    int a = 0;
    --a;
    std::cout << a; // print out -1


**Pre- increment/decrement operators modify the value of the target object
before processing the current statement.**

.. code-block:: cpp

    int a = 0;
    int b = --a;
    std::cout << "a=" << a;
    std::cout << "b=" << b;
    // what is a? what is b? try this!

An Exercise
+++++++++++

Take a look at the following program:

.. code-block:: cpp
    :linenos:

    int i1 = 1;
    int i2 = ++i1;
    int i3 = ++ ++i1;
    int i4 = i1++;
    // we cannot do i1++ ++
    std::cout << "i1 = " << i1 << "\n"
              << "i2 = " << i2 << "\n"
              << "i3 = " << i3 << "\n"
              << "i4 = " << i4 << "\n";

.. _lec3_logic_ops:

Comparison & Logical Operations
-------------------------------

To compare two values, you need to use comparison operators in `C++`_:

1. :code:`<`: strictly less than
2. :code:`>`: strictly greater than
3. :code:`<=`: less than or equal to
4. :code:`>=`: greater than or equal to
5. :code:`==`: equal to
6. :code:`!=`: not equal to

The resulting object of the comparison operators are boolean flags, i.e. either
:code:`true` or :code:`false`.
