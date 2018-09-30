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

Run this example in :nblec_3:`inc_dec`.

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

For logical operators, we have:

1. :code:`&&`: logical and
2. :code:`||`: logical or
3. :code:`!`: logical not (use as unary operator)
4. :code:`^`: logical xor

.. note::

    Technically speaking, :code:`^` is a bitwise operator not a logical
    operator. However, since ``true`` can be converted into integer 1 and
    0 for ``false``, and :code:`1^0=1`, :code:`1^1=0`, and :code:`0^0=0`,
    which behave exactly like an xor operation.

.. code-block:: cpp

    std::cout << "1<2 and 2<3 is: " << (1<2 && 2<3);
    std::cout << "3==4 || 3==6/2 is: " << (3==4 || 3==6/2);
    std::cout << "not 1.0<0.0 is: " << (!(1.0<0.0));
    std::cout << "either 10>2 or 5>2 but not both: " << ((10>2)^(5>2));

Try out comparison and logical operators in :nblec_3:`logi_comp`.

.. _lec3_common_math:

Common Mathematical Operations
------------------------------

As applied scientists who do programming, there is not doubt that using common
mathematical functions is necessary. Unlike `MATLAB`_, in which the common
mathematical functions are defined as built-ins, `C++`_ doesn't know how to
do math by default (sigh...). Fortunately, the *standard math library* provides
most common mathematical operations that can potentially become very handy.

.. code-block:: cpp

    #include <cmath>  // standard math interface

    ...

    std::cout << "sin(pi) is: " << std::sin(M_PI);
    std::cout << "cos(0) is: " << std::cos(0.0);
    std::cout << "arcsin(1) is: " << std::asin(1.0);
    std::cout << "log 2 of base 2 is: " << std::log2(2);
    std::cout << "|-1| is: " << std::abs(-1);

For a complete list and the usage, please refer to
`Standard library header <cmath> <https://en.cppreference.com/w/cpp/header/cmath>`_.

Try out this :nblec_3:`math`.

.. _lec3_ptr_arith:

Pointer Arithmetic
------------------

Again, pointers... `C++`_ allows you to perform arithmetic operations on
pointers. Of course, the means are different from
:ref:`the elementary arithmetic operations <lec3_arith_ops>`. You can add or
subtract an integer from a pointer, e.g.

.. code-block:: cpp
    :linenos:

    int obj[2];
    int *ptr = obj; // equiv to ptr = &obj[0]
    int *ptr_next = ptr+1;
    int *ptr_ori = ptr_next-1;

Here, adding one to ``ptr`` meaning that advance ``ptr`` to next memory address
thus resulting the next adjacent pointer, i.e. ``ptr_next``. Similarly, in line
4, subtracting one from a pointer meaning that move the pointer to its previous
adjacent position, i.e. ``ptr_ori``.

.. note::

    Adding/subtracting integers from a pointer result another pointer.

You can also subtract two pointers, e.g. :code:`ptr1-ptr2`. The result is an
integer that represents the *signed distance* between the two pointers.

.. code-block:: cpp

    float a[2];
    float *ptr_a = a, *ptr_b = ptr_a+1;
    std::cout << "distance in memory between a[0] and a[1] is: " << (ptr_a-ptr_b); // -1


:ref:`Increment and decrement operators <lec3_inc_dec_ops>` are also applicable
to pointers, i.e.

.. code-block:: cpp
    :linenos:

    int arr[5] = {1,2,3,4,5};  // an array of length 5
    int *ptr = arr;
    std::cout << *ptr; // 1
    std::cout << *ptr++; // 1, why??
    std::cout << *++ptr; // 3
    std::cout << *ptr--; // 3, where is ptr now?

Let's take a look at the code above. Line 1 and 2 define an array of size 5 and
initialize its value to :code:`{1,2,3,4,5}`, then define a pointer ``ptr`` that
points to the array.

Line 3 simply shows the value of :code:`arr[0]` by deferencing :code:`ptr`.
Line 4 will first prints the value of :code:`*ptr` then advances ``ptr`` to its
nest position, i.e. :code:`arr[1]`. Line 5 first advances ``ptr`` to
:code:`arr[2]` and displays its value.

For more, take a look at this :nblec_3:`ptr_arith`.

.. _lec3_stm:

Control Statements
==================

.. contents::
   :local:
   :backlinks: top

A statement in `C++`_, roughly speaking, is a single line of code that ends
with semicolon, i.e. :code:`;`, which can be executed by the program.

Control statements are special statements in `C++`_ (or any other programming
languages) that control how/whether other statements will be executed. With
:ref:`my fundamental assumption <intro_fund>`, I will not go detail in the
concept of control statements. I will mainly focus on introducing the
syntax and giving examples.

.. note::

    It's probably a good idea to review the concept of
    :ref:`scope <lec1_scope>` in `C++`_.

In general, control statements in `C++`_ can be put into three families:

1. Conditional statements
2. Loop statements
3. Jump statements

.. _lec3_stm_cond:

Conditional Statements
----------------------

`C++`_ provides two control statements to perform conditional executions.

.. _lec3_stm_cond_if:

The :code:`if` Statement
++++++++++++++++++++++++

An :code:`if` statement conditionally execute another statement based on
whether or not a specified condition is ``true``.

.. code-block:: cpp

    if (<condition>) {
        // do things if <condition> is true
    }

For example:

.. code-block:: cpp
    :linenos:

    std::string dep;
    std::cout << "enter the department:";
    std::cin >> dep;
    if (dep == "ams") {
        std::string course;
        std::cout << "enter the class number:";
        std::cin >> course;
        std::cout << "welcome to ams" << course << std::endl;
    }

Line 4-9 will only be executed if the input ``dep`` is :code:`"ams"`. Compile
and run this program.

Of course, you can add ``else`` so that the condition is complete, the syntax
is:

.. code-block:: cpp

    if (<condition>) {
        // do things if <condition> is true
    } else {
        // do things if not <condition>
    }

For example:

.. code-block:: cpp
    :linenos:

    unsigned n;
    std::cout << "enter a non-negative whole number:";
    std::cin >> n;
    std::string odd_or_even;
    if (n%2) {
        odd_or_even = "odd";
    } else {
        odd_or_even = "even";
    }
    std::cout << "you just entered an " << odd_or_even << " number\n";

Multiple (more than 2) condition branches are supported with :code:`else if`
statement, the syntax is:

.. code-block:: cpp

    if (<condition1>) {
        // do things if <condition1> is true
    } else if (<condition2>) {
        // do things if <condition2> is true
    } else if (<condition3>) {
        // do things if <condition3> is true
    } else {
        // ow
    }

.. note::

    Multiple condition branches are executed in sequential order, and the
    statement will terminate til reach the first ``true`` case of the end of
    the ``if`` statement.

.. note::

    A :code:`if-else if-else if-...-else` is considered as a **single**
    statement!

Let's take a look at the following two different programs:

.. code-block:: cpp

    const int n = 2;
    int a;
    if (n == 2) {
        a = 100;
    } else if (n % 2 == 0) {
        a = 200;
    } else {
        a = 300;
    }
    std::cout << "a=" << a << std::endl;

What is the value of ``a``?

.. code-block:: cpp

    const int n = 2;
    int a;
    if (n == 2) {
        a = 100;
    }
    if (n%2 == 0) {
        a = 200;
    }
    if (n%2) {
        a = 300;
    }
    std::cout << "a=" << a << std::endl;

What about this one?

Command Line Inputs
```````````````````

So far, our :ref:`main <intro_simple_cpp_main>` functions are defined without
any input arguments. However, it's common to have ``argc`` and ``argv`` as the
function input parameters, i.e.

.. code-block:: cpp

    // main.cpp
    int main(int argc, char *argv[]) {
        return 0;
    }

Where ``argc`` is an integer and ``argv`` is an :ref:`array<lec1_array>` of
:ref:`C-strings <lec1_cstr>`. So what are the meanings of these variables?
``argc`` indicates the number of input arguments from command line when the
program is executed, and ``argv`` stores their values in raw strings.

For instance, you can :ref:`compile <intro_simple_cpp_compile>` the program
into an executable binary :code:`a.out` by:

.. code-block:: console

    $ g++ -std=c++11 main.cpp

Then, you can run the program by:

.. code-block:: console

    $ ./a.out

Which means the command line arguments is :code:`./a.out`. In the program,
``argc`` is 1 and the first element (C-string) in ``argv``, i.e.
:code:`argv[0]`, stores the name of the executable---:code:`./a.out`.

.. note::

    All programs have at least one command line argument, which stores their
    names.

If you type:

.. code-block:: console

    $ ./a.out 1 2 3 abc

The program's ``argc`` is 5 with :code:`argv={"./a.out","1","2","3","abc"}`.

The functionality of command line inputs is important, because it enables
*batch processing* with user inputs.

.. note::

    In most cases, interactive inputs, e.g. through :code:`std::cin`
    and keyboards, are not possible, especially for scientific computing where
    programs usually run on clusters.

Now, combining this information with ``if`` statement, you can parse the user
command line inputs. In addition, it's common that you want the user to pass
some numerical values, so converting from C-strings to integral/floating
numbers is necessary. This can be done with the functions :code:`std::atoi`
and :code:`std::atof` that are defined in official :code:`<cstdlib>` library.

.. code-block:: cpp

    # include <cstdlib>

    ...

    const char * i_str = "4";
    const char * f_str = "1e-1";
    const int i = std::atoi(i_str);
    const double f = std::atof(f_str);
    // i is 4 and f is 0.1

.. hint::

    Check the number of input arguments by :code:`if (argc < 3) ...`

.. only:: html

    Compile and run :download:`cmd_inputs.cpp<../../programs/3/cmd_inputs.cpp>`.

.. only:: latex

    Compile and run :cpplec_3:`cmd_inputs`.

.. _lec3_stm_cond_switch:

The :code:`switch` Statement
++++++++++++++++++++++++++++

.. _lec3_stm_loop:

Loop Statements
---------------

.. _lec3_stm_jump:

Jump Statements
---------------
