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
