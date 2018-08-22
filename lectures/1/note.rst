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

Commonly Used Types
-------------------

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
    an array of characters, i.e. :cpp:expr:`char`.

Literals
--------

Literals are constant values of any programs. In `C++`_ (almost all other
languages), there are five types:

1. integer literals,
2. floating point literals,
3. character literals,
4. boolean literals, and
5. string literals.

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

.. _lec1_define_init:

Define & Initialize Variables
-----------------------------

.. _lec1_scope:

Scope & Lifetime of Variables
-----------------------------
