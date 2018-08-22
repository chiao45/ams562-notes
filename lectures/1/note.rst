.. include:: ../../links.txt
.. include:: ../../roles.txt

.. _lec1:

`C++`_ is all about TYPES!
==========================

.. contents:: Table of Contents
   :local:
   :backlinks: top

Unlike `Python`_ (or any other dynamic languages), all `C++`_ variables must be
initialized with their types explicitly given. And the variable names cannot be
reused within the same :ref:`cope<lec1_scope>`. Consider the following
`Python`_ code

.. _lec1_dy_eg:

.. ipython::

    In [1]: a = 1

    In [2]: type(a)
    Out[2]: int

    In [3]: a = 1.0

    In [4]: type(a)
    Out[4]: float

    In [5]: a = 'a'

    In [6]: type(a)
    Out[6]: str

In the program, variable :python:`a` first is initialized as an integer, but
later on it switches to floating point number and string. **This, however, is
not allowed in C++.**

.. _lec1_builtin:

The Built-in Types
------------------

A built-in is a component that comes with the programming language; using
built-in components does not require you import any external interfaces
(even including official ones). In `C++`_, we have built-in data types that
define the foundation of the language (or even other languages). The built-in
types can be mainly divided into three groups:

1. integral types,
2. floating number types, and
3. the valueless type, i.e. ``void``.

.. _lec1_builtin_int:

The Integral Types
++++++++++++++++++

Let's put item 3 apart now. The integral types can be further categorized into:

- integers
- characters
- boolean

Integers
````````

Integers types are used to store the whole numbers in programming. The most
commonly used one is probably :cpp:expr:`int`. For integers, both **signed**
and **unsigned** versions are provided, where the former allows negative
values.

.. table:: Integer Types Table
    :name: int_table

    =========================== ============ ================================
    Types                       Size (bytes) Range
    =========================== ============ ================================
    :cpp:expr:`short`            2            -32,768 to 32,767
    :cpp:expr:`unsigned short`   2            0 to 65,535
    :cpp:expr:`int`              4            -2,147,483,648 to 2,147,483,647
    :cpp:expr:`unsigned int`     4            0 to 4,294,967,295
    :cpp:expr:`long`             8            -2^63 to 2^63-1
    :cpp:expr:`unsigned long`    8            0 to 2^64-1
    =========================== ============ ================================

.. warning::

    In general, the sizes of integer types are platforms and compilers depended.
    The above information is for GCC with 64bit machines (as our docker image).
    On some old machines, you may find that the sizes of :cpp:expr:`int` and
    :cpp:expr:`long` are 2 and 4 byte, respectively. In order to have 64bit
    (8-byte) integer, you need :cpp:expr:`long long`.

.. note::

    :cpp:expr:`signed` is also a keyword in `C++`_, but using it is optional, i.e.
    :cpp:expr:`signed int` is identical to :cpp:expr:`int`.

Characters
``````````

The keyword to store character data is :cpp:expr:`char`, whose size must be 1
byte. :cpp:expr:`char` ranges from :math:`[-128,127]` and :math:`[0, 255]` for
:cpp:expr:`unsigned char`.

Boolean
```````

A :cpp:expr:`bool` is used to store logical values, i.e. either
:cpp:expr:`true` or :cpp:expr:`false`. Typically, the size of :cpp:expr:`bool`
is 1 byte (in theory, we only need 1 bit).

.. warning::

    :cpp:expr:`signed` and :cpp:expr:`unsigned` are not applicable to
    :cpp:expr:`bool`

.. _lec1_builtin_flt:

Floating Numbers
++++++++++++++++

Clearly, integers are not enough! Especially in scientific computing, we need
real numbers that can store data from our models. In `C++`_, the concept of
*floating numbers* is used to represent real numbers. Like the
:ref:`integer<int_table>` table, the following is the table of floating numbers

.. table:: Floating Numbers Table
    :name: flt_table

    ======================= ============ ===========================================
    Types                   Size (bytes) Range
    ======================= ============ ===========================================
    :cpp:expr:`float`       4            :math:`±1.18e^{-38}` to :math:`±3.4e^{38}`
    :cpp:expr:`double`      8            :math:`±3.36e^{-308}` to :math:`±1.8e^{308}`
    :cpp:expr:`long double` ID           ID
    ======================= ============ ===========================================

where *ID* stands for *implementation depended*.

.. note::

    The size and range of :cpp:expr:`long double` is implementation depended.
    The size may be 8, 12, or 16 bytes depending on different compilers. In
    general, :cpp:expr:`long double` is not a commonly used type.

Precision
`````````

The fact is that floating numbers, in general, cannot represent real numbers
**exactly**. This is particularly true for irrational numbers, i.e.
:math:`\sqrt{2}`, :math:`\pi`, etc. We refer :cpp:expr:`float` as
*single-precision format* [#]_ while *double-precision format* [#]_ for
:cpp:expr:`double`.

.. table:: Floating Numbers Precision Table
    :name: flt_prc_table

    ================ ===========================================
    Precision        *Significant digits* [#]_
    ================ ===========================================
    single-precision typically 7
    double-precision typically 15
    ================ ===========================================

For instance, given two real numbers :math:`1.1` and :math:`1.100000004`, which
are, of course, different numbers in the exact arithmetic setting. However,
under single-precision format, they are equal. What about double-precision?
Checkout :nblec_1:`precision`.

Double-precision format is about twice accurate than single-precision, and has
a much wider range. **Question:** what are the points of using single-precision
numbers?

.. [#] please read `Wikipedia page <https://en.wikipedia.org/wiki/Single-precision_floating-point_format>`_ for more
.. [#] please read `Wikipedia page <https://en.wikipedia.org/wiki/Double-precision_floating-point_format>`_ for more
.. [#] please read `Wikipedia page <https://en.wikipedia.org/wiki/Significant_figures>`_ for more

.. _lec1_str:

The :cpp:expr:`string` Type
---------------------------

``string`` is also an important type in all programming language. With standard
`C++`_, ``string`` is not a built-in type, it's defined in the standard library
``<string>``. Therefore, including the interface is needed for using strings.

.. code-block:: cpp
    :linenos:
    :emphasize-lines: 1

    #include <string>

    std::string name = "John";
    std::string age = "32";

.. note::

    If you are familiar with C, there is so-called C-string type, which is
    an :ref:`array<lec1_array>` of characters, i.e. :cpp:expr:`char`.

Literals
--------

Literals are constant values of any programs. In `C++`_ (almost all other
languages), there are five types:

1. integer literals,
2. floating point literals,
3. character literals,
4. boolean literals, and
5. string literals.

.. _lec1_literal_type:

Each literal has its own **form** and **type**. Notice that literals are
commonly used in :ref:`initializing<lec1_define_init>` variables.

Integer Literals
++++++++++++++++

Examples of integer literals are:

.. code-block:: cpp

    32, 1, -2, -100, 30001, ...

Their **types** are :cpp:expr:`int`. Then, how to specify literals of other
integer types? You need suffix :cpp:expr:`u` and :cpp:expr:`l` (ell), where the
former represents :cpp:expr:`unsigned` and the latter is for :cpp:expr:`long`
types:

.. code-block:: cpp

    32l     // long literal
    32u     // unsigned int literal
    32ul    // unsigned long literal

.. note::

    There does not exist numeric literals for :cpp:expr:`short` and
    :cpp:expr:`unsigned short`.

Floating Point Literals
+++++++++++++++++++++++

The following forms:

.. code-block:: cpp

    1.0, 2.0, 3.0, 4.0, ...

are all double-precision floating number literals. Suffix :cpp:expr:`f` is used
to denote single-precision, i.e. :cpp:expr:`float`.

.. code-block:: cpp

    1.0f    // float 1
    -2.0f   // float -1
    -5.21f  // float -5.21

You can also use scientific notations:

.. code-block:: cpp

    1.0e0   // double, 1x10^0, i.e. 1
    2.0e-3  // double, 2x10^-3, i.e. 0.002, or
    2e-3

    1.e10f      // float, 1x10^10
    5.32001e3f  // float, 5320.01

Character Literals
++++++++++++++++++

For character literals, use the single quotations:

.. code-block:: cpp

    'a'     // character a
    'A'     // character A
    '7'     // character 7

Boolean Literals
++++++++++++++++

`C++`_ uses :cpp:expr:`true` and :cpp:expr:`false` for Logical literals.

String Literals
+++++++++++++++

For strings, `C++`_ uses double quotations, for instance:

.. code-block:: cpp

    "Hello World!"      // string value of Hello World!
    "AMS 562"           // string of AMS 562

A string is a sequence of characters.

.. warning::

    In `Python`_, single quotations can be used for strings, i.e. see the
    :ref:`Hello World<intro_py_hw>` example. However, this rule cannot be
    applied to `C++`_, i.e. :code:`'abc'` is referred as multicharacter
    literal that has type of :cpp:expr:`int` instead of :cpp:expr:`char` and
    the value is ID.

Escape Sequences
++++++++++++++++

**Questions:** How to use literals to represent string :code:`"A"` and
character :code:`'` with the quotation marks?

Such special characters are so-called *escape sequences* and start with
backslash. Commonly used ones are:

.. table:: Commonly Used Escape Sequences (ES) [#]_
    :name: es_table
    :align: center

    =========== ================
    ES          Description
    =========== ================
    :code:`\'`  single quote
    :code:`\"`  double quote
    :code:`\\`  backslash
    :code:`\n`  **new line**
    :code:`\t`  horizontal tab
    :code:`\v`  vertical tab
    =========== ================

Now let's consider the following string literals with escape sequences:

.. code-block:: cpp

    "Hello\nWorld!"         // Hello<new line>World!
    "Hello\tWorld!"         // Hello<tab>World!
    "\"Hello World\""       // "Hello World!"

.. [#] Check `cppreference page <https://en.cppreference.com/w/cpp/language/escape>`_ for more.

.. _lec1_define_init:

Define & Initialize Variables
-----------------------------

At the beginning of this lecture, we have showed an
:ref:`Python program<lec1_dy_eg>` to demonstrate one of the major differences
between `C++`_ and dynamic language. In `C++`_, you must to explicitly
construct variables with their types given. The format is :code:`[type] var;`,
where :code:`[type]` is legal types, e.g. :cpp:expr:`int`, :cpp:expr:`double`,
:cpp:expr:`std::string`, etc.

Define Variables
++++++++++++++++

Here are some examples of defining variables:

.. code-block:: cpp

    int a;              // define an integer with var name a
    double tol;         // define a double with var name tol
    std::string addr;   // define a string with var name addr, req <string>

.. warning::

    Once a variable name is been occupied, you cannot reuse it for anything
    else (within the same :ref:`scope<lec1_scope>`).

Initialize Variable Values
++++++++++++++++++++++++++

It's good practice to initialize a variable while defining it.

.. code-block:: cpp

    unsigned long size = 100000000000ul;    // a huge size
    float error = 0.0f;                     // initialize to 0
    std::string filename = "input.txt";     // a string of filename

Checkout :nblec_1:`types` and run it.

.. note::

    One should not expect any default behaviors of uninitialized variables,
    e.g. when you write :code:`int a;`, :cpp:expr:`a` might be zero but you
    should not assume this!

Type Conversions
++++++++++++++++

Let's take a look at the following seemingly trivial code:

.. code-block:: cpp

    double two = 2;

It defines a double-precision floating point number :cpp:expr:`two` and
initializes it to 2. However, recall that each literal has its own
:ref:`type<lec1_literal_type>`, which means the above code assigns a double
precision number with an integer. This is called type conversion in `C++`_.

Type Conversions Between Integers
+++++++++++++++++++++++++++++++++

In general, type conversions between integers are simply copying the values.
However, keep in mind that all integer types have their ranges. Converting
from larger size types to smaller ones may potentially cause troubles, i.e.
integer *overflow* and *underflow*.

.. code-block:: cpp
    :name: conv_int

    unsigned int wha = -1; // What the value of wha??

Typically, the issues come from converting between signed and unsigned
integers. Let's take a look at the :ref:`code<conv_int>` above. It tries to
convert :cpp:expr:`int` value -1 to :cpp:expr:`unsigned int` variable
:cpp:expr:`wha`.

.. note::

    You can consider each integer type form a cyclic list that :code:`MAX+1`
    is its :code:`MIN` and :code:`MIN-1` is the :code:`MAX`.

As a result, the actual value of :cpp:expr:`wha` is 4,294,967,295. Checkout and
run :nblec_1:`conv`.

.. warning::

    Unless you 100% know what you are doing, converting between signed and
    unsigned integers should be avoid!

Converting Floating Point Numbers to Integers
+++++++++++++++++++++++++++++++++++++++++++++

The rule for converting floating numbers to integers is to truncate them into
whole numbers.

.. code-block:: cpp

    int a = 12.03;    // a is 12
    int b = -1.234e2; // b is -123

The :code:`const` Specifier
---------------------------

:code:`const` is a keyword in `C++`_ that indicates an variable is immutable.
Once a variable is defined as constant, you cannot modify its value,
**so initialization is must for defining constant variables!**

.. code-block:: cpp

    const int a = 4;    // define a constant integer of value 4
    // a = 2;           // ERROR! you cannot modify constant vars
    // const double b;  // ERROR! const var must be initialized

.. tip:: Use :code:`const` whenever possible!

.. _lec1_array:

Array
-----

Array is one of the most basic data structures in programming. As a matter of
facet, it is also the most commonly used data structure in scientific
computing. An array is a sequence of objects that have the same size and type.
In `C++`_, an array can be constructed with square bracket :code:`[N]`, where
:cpp:expr:`N` is the size of array.

.. code-block:: cpp

    double arr[3];   // create an array of 3 doubles
    int pos[5];      // an array of 5 integers

To initialize an array, the curly brackets :code:`{}` are needed, e.g.

.. code-block:: cpp
    :linenos:

    double tols[2] = {1e-4, 2e-5};  // array of two with values 1e-4 and 2e-5
    int mappings[] = {2, 0, 1};     // array of three integers, size 3
    // short a[];                   // ERROR! size must be provided
    // const int b[2];              // ERROR! b must be initialized
    int z[3] = {1};                 // partial initialization is ok
    // int m[2] = {1,2,3};          // ERROR! exceeded the size

It is allowed to implicitly provide the size if you initialize the array, as
shown in line 2. Also, partially initialize an array is allowed, but the
right-hand side must be no larger than the actual array size. Checkout and
run :nblec_1:`array`.

Accessing Array Elements
++++++++++++++++++++++++

To access an specific element of an array, we need to use operator
:code:`[index]`.

.. warning::

    Un like Fortran and `MATLAB`_, `C++`_ is zero-based indexing, i.e. the
    first element index starts from 0 instead of 1.

.. code-block:: cpp

    double stdv[3];     // array of 3 doubles
    stdv[0] = 1.0;      // first element 1
    stdv[1] = 2.0;      // second element 2
    stdv[2] = 3.0;      // last element 3
    // stdv[3];         // out of bound!

Multidimensional Array
++++++++++++++++++++++

Multidimensional arrays are useful, for instance, a matrix can be represented
as a 2D array, where the first dimension is the row size and column size for
the second dimension. The concept of multidimensional array can be interpreted
as *an array of arrays*.

.. code-block:: cpp
    :linenos:

    double mat[2][2];       // array of two arrays of size 2
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[1][0] = 3;
    mat[1][1] = 4;
    /*
        a matrix of 2x2

        | 1  2 |
        | 3  4 |
    */

What is the type of :cpp:expr:`mat`? It is an array but its elements also have
type of array, i.e. :code:`double[2]`. In line 2, :code:`mat[0][0]` first
accesses to the first element of :cpp:expr:`mat`, which is an array, say
:cpp:expr:`mat0`, the accesses the first element of :cpp:expr:`mat0`, i.e.
:code:`mat0[0]`.

The :code:`char[]`
++++++++++++++++++

As we already learned in section :ref:`string<lec1_str>`, a string is just
a sequence of :cpp:expr:`char`, i.e. :code:`char[]`. Therefore, :code:`char[]`
is also called *C string*, or the native string type of `C++`_.

.. _lec1_scope:

Scope & Lifetime of Variables
-----------------------------
