.. include:: ../../links.txt
.. include:: ../../roles.txt

.. _lec5:

.. contents:: Table of Contents
   :local:
   :depth: 1
   :backlinks: top

Toward `C++`_ Packages/Libraries
================================

.. contents::
   :local:
   :backlinks: top

We can't just live with a single ``main`` function, well, technically you can,
but the obvious shortage is that your ``main`` script will become extremely
large and eventually become unmaintainable.

During the development of your main programs, you main find some of the
functions (in general, interface methods) are very valuable and you want to
reuse them in the future or share with others (great!).

In such situations, you want to implement a *library*.

.. _lec5_pack_sep:

Separate Interfaces and Implementations
---------------------------------------

As we already learned, for a program to use an object (variable, function,
or class), you just need to make sure its declaration can be seen prior to
the execution statement. The actual implementation/definition can go after the
declaration, e.g. having the function prototype before the ``main`` function
and its implementation of the ``main``.

.. code-block:: cpp

    extern const int a;  // declaration
    int main() {
        std::cout << "a=" << a <<std::endl;
    }
    // define a
    const int a = 100;

Header Files
++++++++++++

Roughly speaking, *interfaces* are declarations and usually lie in
*header files*, i.e. ``*.hpp``, ``*.hxx``, ``*.H``, ``*.h++``, ``*.h``, etc.
And you use :code:`#include` to bring in their declarations.

.. code-block:: cpp

    #include <iostream>

    // now, std::cout, std::cin, std::cerr are seen

    #include <cmath>

    // now std::sin, std::cos, std::log ... are seen

    #include <string>

    // now std::string, std::to_string ... are seen

.. tip::

    The :code:`#include` can be used with angle brackets, i.e. ``<>``, or
    double quotation marks, i.e. ``""``. Typically, the former is for system
    libraries, e.g. standard libraries such as ``iostream``, ``cstdlib``,
    ``cmath``, etc. The latter is used for local and/or user-defined interfaces.

Take the example of computing derivatives, we can put the ``diff`` in a header
file called ``diff.hpp``

.. code-block:: cpp

    // in diff.hpp

    // prototype of diff
    // f is input function
    // x is evaluated point
    // h is differential spacing
    double diff(double (*f)(double), const double x, double h = 1e-5);

Now, in the main function, you can :code:`#include` the ``diff`` interface.

.. code-block:: cpp

    // main.cpp

    #include <cmath>
    #include <iostream>

    // bring in diff
    #include "diff.hpp" // double quotation marks

    int main() {
        std::cout << "sin\'(1)=" << diff(std::sin, 1)  << std::endl;
        return 0;
    }

.. tip::

    Personally, I think the best way to under stand :code:`#include` is
    *copy/paste*, i.e. copy the contents in the file that is included and paste
    them at where :code:`#include` appears.

Now, open the terminal and compile the program.

.. code-block:: console

    $ g++ main.cpp
    /tmp/cced5cZh.o: In function 'main':
    main.cpp:(.text+0x46): undefined reference to 'diff(double (*)(double), double, double)'
    collect2: error: ld returned 1 exit status

We got an error, which is expected, because we have not yet define the function
``diff``.

.. note::

    ``undefined reference to`` is a common error message that indicates missing
    definitions to certain interfaces.

Source Files
++++++++++++

*Source files* are files that hold the implementations of the interfaces that
are defined in their corresponding header files.

.. code-block:: cpp

    // in diff1.cpp
    #include "diff.hpp"  // first include the interface

    // define diff, notice that default argument is dropped
    // first order scheme
    double diff(double (*f)(double), const double x, double h) {
        if (h <= 0.0) {
            h = 1e-5;
        }
        return (f(x + h) - f(x)) / h;
    }

With the source code implementation, we can now compile our program as:

.. code-block:: console

    $ g++ main.cpp diff1.cpp -o main
    $ ./main
    sin'(1)=0.540298

Notice that we have included the source file in our compiled file list, this
is called *implicit linking*.

.. warning::

    You can have as many file as you want in the compiled file list, but
    **only** one ``main`` function can exist. Moreover, each implementation
    must be unique!

Take a look at the :ziplec_5:`diff`.
