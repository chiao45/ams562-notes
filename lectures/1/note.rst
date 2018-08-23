.. include:: ../../links.txt
.. include:: ../../roles.txt

.. _lec1:

.. contents:: Table of Contents
   :local:
   :depth: 1
   :backlinks: top

.. _lec1_types:

`C++`_ is all about TYPES!
==========================

.. contents::
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

.. _lec1_str_lit:

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

.. _lec1_es:

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

.. _lec1_array_cstr:

The :code:`char[]`
++++++++++++++++++

As we already learned in section :ref:`string<lec1_str>`, a string is just
a sequence of :cpp:expr:`char`, i.e. :code:`char[]`. Therefore, :code:`char[]`
is also called *C string*, or the native string type of `C++`_. You can
initialize a C string either using the array fashion or the
:ref:`string literal<lec1_str_lit>` way.

.. code-block:: cpp

    // The follow two are identical
    char str1[] = "AMS 562";
    char str2[] = {'A', 'M', 'S', ' ', '5', '6', '2'};

.. _lec1_scope:

Scope & Lifetime of Variables
-----------------------------

We have already learned that reusing a variable name is not allowed in `C++`_,
but this rule applies to the variables with the same scope. Scope operators
must appear as a pair of scope opener and scope closer, where are :code:`{`
and :code:`}`, respectively.

.. code-block:: cpp

    int a = 1;   // define integer a
    // double a; // ERROR! reusing a within the same scope

    // start a new scope
    {
        double a; // OK!
    }
    // scope ends

.. note::

    The :ref:`main<intro_simple_cpp_main>` function or any other
    functions all have local scope.

The lifetime of a variable is associated with its scope. When it reaches the
end of scope, it will become inaccessible and be popped out from the program
stack.

.. code-block:: cpp
    :linenos:

    // start with a child scope
    {
        int a;
    } // a becomes invalid!

    // a = 1; // ERROR! a does not exist!!

    int b = 1; // define b, and its life begins

    {
        double b = 2.0; // define local b
        b = 3;
        // which b?
    }

    b = 2;
    // which b?

.. note:: Child scope overwrites its parent scopes.

.. _lec1_io:

Standard Input & Output
=======================

.. contents::
   :local:
   :backlinks: top

.. _lec1_io_stdout:

The :cpp:expr:`std::cout` Stream
--------------------------------

By default, most program environments' standard output is screen. In `C++`_,
the global object :cpp:expr:`std::cout` is defined and guaranteed to be
initialized at the beginning of any programs. The object itself is defined in
the standard I/O library :code:`<iostream>`, which must be included in order
to perform I/O tasks.

**std::cout** stands for standard C output, which is a :cpp:expr:`FILE*`
object in C (:python:`sys.stdout` in `Python`_). `C++`_ uses the abstraction
called *streams* to perform I/O operations.

Output operator :code:`<<` (bitwise left shift, or double less-than signs) is
used to indicate "write to a streamer".

.. code-block:: cpp
    :linenos:

    #include <iostream>  // bring in std::cout

    std::cout << "Hello World!" << std::endl;
    std::cout << "1+1=" << 2 << std::endl;
    std::cout << "size of double is: " << sizeof(double) << std::endl;

Notice that :cpp:expr:`std::endl` is *manipulator* to produce a newline.
Line 4 and 5 show that you can recursively write to the :cpp:expr:`cout`
streamer and the output contents can be different types, e.g. in line 4,
:code:`"1+1="` is string but :code:`2` is integer.

.. note::

    In stead of using manipulator :cpp:expr:`std::endl`, you can also use the
    newline :ref:`escape sequence<lec1_es>`---:code:`\n`.Therefoer, the outputs
    are identical between :code:`std::cout << "Hello World!" << std::endl;` and
    :code:`std::cout << "Hello World!\n";`.

Checkout and run :nblec_1:`cout`.

The :cpp:expr:`std::cin` Stream
-------------------------------

The default standard input for most program environments is through keyboard.
In C, the :cpp:expr:`FILE*` object is :cpp:expr:`stdin` (:python:`sys.stdin`
in `Python`_). This input streamer is able to read the user inputs from
keyboard. :cpp:expr:`std::cin` stands for standard C input.

Similar to output operator, the input operator is bitwise shift right (or
double greater-than signs) :code:`>>`. The basical syntax is
:code:`std::cin>>var;` and the user inputs will be stored in :code:`var`.

.. code-block:: cpp

    #include <iostream> // cout and cin

    // best practice, always indicate the user what to enter
    std::cout << "Please enter your first name:\n";
    std::string name;
    // the program will hang here til recieve the user input
    std::cin >> name;
    std::cout << "Hello! " << name << std::endl;

:cpp:expr:`std::cin` searches the user keyboard input and treated them as a
sequence of white space separated arguments. Therefore, if you enter your
full name, e.g. "Qiao Chen", only the first value will be printed because
the program only asks for one input arguments.

It's also possible to handle multiple input arguments:

.. code-block:: cpp

    #include <iostream> // cout and cin

    // best practice, always indicate the user what to enter
    std::cout << "Please enter your first and last names:\n";
    std::string fname, lname;
    // the program will hang here til recieve the user input
    std::cin >> fname >> lname;
    std::cout << "Hello! " << fname << ' ' << lname << std::endl;

.. only:: html

    Compile and run :download:`cin_demo.cpp<../../programs/1/cin_demo.cpp>`.

.. only:: latex

    Compile and run :cpplec_1:`cin_demo`.

The :cpp:expr:`std::cerr` Stream
--------------------------------

:cpp:expr:`std::cerr` stands for standard C error output. Its associated C
:cpp:expr:`FILE*` object is :cpp:expr:`stderr` (:python:`sys.stderr` in
`Python`_). It, like :ref:`cout<lec1_io_stdout>`, is an output streamer. It
also writes outputs on the screen.

.. code-block:: cpp

    #include <iostream>

    std::cerr << "This is an error message!\n";
    std::err << "WARNING! Converting from signed to unsigned is dangerous!\n";

:cpp:expr:`std::cout` vs. :cpp:expr:`std::cerr`
-----------------------------------------------

Conceptually, we understand that :cpp:expr:`std::cout` should be used for
writing normal messages, e.g. logging information; :cpp:expr:`std::cerr`, on
the other hand, should be used for indicating error messages. However,
in terms of programming, what is the difference between these two streamers,
since they seemingly both just output messages on the screen.

Before we dig into this question, we need to understand the concept
*file descriptor* (FD). FD is a handle (usually non-negative integer) that
uniquely indicates an open **file** object. On Linux, a file object can also
be other input/output resources such as pipe and network sockets. Recall that
both *cout* and *cerr* stand for *standard outputs*, the latter is specifically
for error output. All these two are the default output FDs, to which a program
can write outputs. On Linus, there should be three standard FDs:

.. table:: Standard File Descriptors
    :align: center

    ====================== =============== ===========
    Streams                  File Types    FD handles
    ====================== =============== ===========
    :cpp:expr:`std::cin`   standard input   0
    :cpp:expr:`std::cout`  standard output  1
    :cpp:expr:`std::cerr`  standard error   2
    ====================== =============== ===========

.. _lec1_io_cmp_eg:

Consider the following program:

.. literalinclude:: ../../programs/1/cout_vs_cerr.cpp
    :language: cpp
    :lines: 11-

.. only:: html

    and you can download it :download:`cout_vs_cerr.cpp<../../programs/1/cout_vs_cerr.cpp>`.

.. only:: latex

    and you can download it :cpplec_1:`cout_vs_cerr`.

Inside a terminal, compile the program:

.. code-block:: bash

    $ g++ cout_vs_cerr.cpp

Let's first run the program normally

.. code-block:: bash

    $ ./a.out
    This is from cout
    This is from cerr

Both of "This is from cout" and "This is from cerr" are printed on the screen.
Bash allows you to *redirect* standard outputs by using :code:`>` when you run
any programs. Now rerun the program:

.. code-block:: bash

    $ ./a.out >cout.txt
    This is from cerr

Only "This is from cerr" is shown on the screen, the output that was written to
:cpp:expr:`cout` had been redirected to the file "cout.txt". Invoke the
built-in commands ``ls`` and ``cat`` to list *cwd* and print out the content
of a file.

.. code-block:: bash

    $ ls
    a.out  cout.txt  cout_vs_cerr.cpp
    $ cat cout.txt
    This is from cout

In addition, you redirect a specific file descriptor by adding the FD handle
in front of :code:`>`. Finally rerun the program:

.. code-block:: bash

    $ ./a.out 1>cout.txt 2>cerr.txt
    $ ls
    a.out  cerr.txt  cout.txt  cout_vs_cerr.cpp
    $ cat cout.txt cerr.txt
    This is from cout
    This is from cerr

This time, both *cout* and *cerr* wrote to files "cout.txt" and "cerr.txt",
respectively. In practice, this allows you easily to group the program outputs
into normal progress logging information and error/warning information. For
instance:

.. code-block:: bash

    $ ./my_prog 1>prog.log 2>error.log

If something goes wrong, the user can always trace back in "error.log" given
the assumption that your program write error/warning messages to
:cpp:expr:`std::cerr`.

.. tip::

    :bash:`&>file.txt` can redirect both *stdout* and *stderr* to "file.txt".
    For instance, :bash:`./a.out &>output.log`.
