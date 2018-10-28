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

Compilation & Linking
+++++++++++++++++++++

Previously, I told you that when you compile a program, say ``demo.cpp``, you
just simply type:

.. code-block:: console

    $ g++ demo.cpp
    $ ./a.out

What happens under the hood is that ``g++`` first compile ``demo.cpp`` into
*machine code*, then link the *object file* with standard `C++`_ libraries.

.. code-block:: console

    $ g++ -c demo.cpp

``-c`` indicates compilation and will yields so-called *object files*, i.e.
:code:`*.o` files. The command above will generate an object file ``demo.o``.

.. code-block:: console

    $ g++ demo.o -o demo
    $ ./demo

The command above is linking that will link the machine code with `C++`_
libraries and produce an executable ``demo``.

The separation of compilation and linking is sometimes referred as *explicit
linking* (the first style is *implicit*).

If we have multiple files, we can still do implicit linking (as we have already
shown in previous section).

.. code-block:: console

    $ g++ demo.cpp src1.cpp src2.cpp ... -o demo
    $ ./demo

The drawback is that it's not portable and will generate a huge executable.

The preferred way is to do explicit linking.

.. code-block:: console

    $ g++ -c src1.cpp
    $ g++ -c src2.cpp
    ...
    $ g++ demo.cpp src1.o src2.o ... -o demo
    $ ./demo

Libraries
+++++++++

We have been keep talking about libraries in `C++`_, in order to create
a (static) library, we need to use GNU archive tool ``ar`` on Linux.

The archive tool is able to create, modify, and extract files from an archive.
On Linux, a (static) library ends with ``.a`` and starts with ``lib``. For
instance, if you have a library that has name of ``demo``, then the archive
name is ``libdemo.a``.

To create an archive/library, you need to invoke:

.. code-block:: console

    $ ar [options] library-file object-files...

Commonly used options are:

1. ``r``: Insert the files member... into archive (with replacement).
2. ``s``: Add an index to the archive, or update it if it already exists.
3. ``v``: Be verbose printing.

Therefore, to create a library (using the demo example above), you can:

.. code-block:: console

    $ ar rsv libdemo.a src1.o src2.o ...
    $ g++ demo.cpp libdemo.a
    $ ./a.out

For a complete list of options and how they work, please refer to the manual
page of ``ar``, i.e. type ``man ar`` in the terminal. Or look at the online
`Linux manual page of ar <https://linux.die.net/man/1/ar>`_.

Additional Compilation/Linking Arguments
++++++++++++++++++++++++++++++++++++++++

During compilation, the headers that are included in the source files are
assumed can be located in either the standard `C++`_ include paths or paths
that exist relative to ``cwd``.

.. note::

    On Linux, there are some standard system-wise `C++`_ include paths besides
    the `C++`_ header files themselves. Typically they are ``/usr/include`` and
    ``/usr/local/include``. Adding files to these two paths requires root
    privilege and is not recommended for libraries that are still under
    development. In addition, for different Linux distributions, there might be
    some different "standard" include paths.

In this case, we need a way that to tell compiler to where to find the header
files included in the source code. GCC allows you to use ``-I`` argument
followed by path argument.

Now, let's consider the following demo source code ``demo_src.cpp`` example:

.. code-block:: cpp

    // demo_src.cpp
    #include "demo_header.hpp"

    // impls ...

We we invoke the compilation command, i.e.

.. code-block:: console

    $ g++ -c demo_src.cpp

It assumes that the header file ``demo_header.hpp`` can be found either
in standard include paths. However, this is, in practice, typically not the
case. In order to tell GCC where to find ``demo_header.hpp``, we need to add
``-I`` switch followed by either relative or absolute path that points to
``demo_header.hpp``.

.. code-block:: console

    $ g++ -c -I/path/to/demo_header.hpp demo_src.cpp

If there are multiple includes, you can add additional ``-I`` switches.

On Linux, linking can be done by explicitly adding the library file with
its relative or absolute path. However, a more common way is to use ``-l``
(ell) followed by the library name. For instance, ``-ldemo`` assumes a library
file with name ``libdemo``.

The problem, link :code:`#include`, ``-ldemo`` assumes that ``libdemo`` can be
found under "standard" library-paths that usually do **NOT** include ``cwd``.
Therefore, if you have ``libdemo.a`` that stays in ``cwd``, then

.. code-block:: console

    $ g++ demo.cpp libdemo.a

works but

.. code-block:: console

    $ g++ demo.cpp -ldemo

does not work because the linker cannot find ``libdemo``.

To overcome this, using the ``-L`` switch to indicate the library search paths,
i.e.

.. code-block:: console

    $ g++ demo.cpp -L/path/to/libdemo -ldemo

A Complete Example
++++++++++++++++++

First download the :ziplec_5:`linking` example, in which a ``hello-world``
project is implemented.

Here is the project structure:

.. code-block:: bash

    linking/
        include1/
            hello.hpp   # hello header file
        include2/
            world.hpp   # world header file
        lib/
        main.cpp        # main program
        hello.cpp       # hello source code
        world.cpp       # world source code


.. code-block:: cpp
    :caption: include1/hello.hpp

    void hello();

.. code-block:: cpp
    :caption: hello.cpp

    #include <iostream>
    #include "hello.hpp"  // under include1
    void hello() {
        std::cout << "Hello ";
    }

.. code-block:: cpp
    :caption: include2/world.hpp

    void world();

.. code-block:: cpp
    :caption: world.cpp

    #include "world.hpp"  // under include2
    #include <iostream>

    void world() {
        std::cout << "World\n";
    }

The main program is:

.. code-block:: cpp
    :caption: main.cpp


    #include "hello.hpp"
    #include "world.hpp"
    int main() {
        hello();
        world();
        return 0;
    }

Clearly, we want our main program to print out ``Hello World`` in the terminal.
To do that, we need first compile the source files ``hello.cpp`` and
``world.cpp``.

.. code-block:: console

    $ g++ -c -Iinclude1 hello.cpp
    $ g++ -c -Iinclude2 world.cpp

.. note:: Relative paths are used here.

Now to compile the main program into object file, we need to add both include
paths since both ``hello.hpp`` and ``world.hpp`` are used in the ``main.cpp``.

.. code-block:: console

    $ g++ -c -Iinclude1 -Iinclude2 main.cpp
    $ ls
    include1/  include2/  lib/  hello.cpp  hello.o  main.cpp  main.o  world.cpp  world.o

Next step is to user ``ar`` to create a library called ``hello-world``.

.. code-block:: console

    $ ar rsv lib/libhello-world.a hello.o world.o
    ar: creating lib/libhello-world.a
    a - hello.o
    a - world.o
    $ ls lib
    libhello-world.a

.. warning::

    Do **NOT** include the ``main.o`` or, generally speaking, definition of the
    ``main`` function into an archive!!

To do the final linking, first try w/o specifying the ``-L`` switch.

.. code-block:: console

    $ g++ main.o -lhello-world
    /usr/bin/ld: cannot find -lhello-world
    collect2: error: ld returned 1 exit status

We need to specify the path to ``libhello-world``.

.. code-block:: console

    $ g++ main.o -L lib -lhello-world
    $ ./a.out
    Hello World

.. tip:: Space is allowed between paths and ``-I``/``-L``.

Makefiles
=========

In practice, for relatively large projects, manually doing compilation and/or
linking is infeasible. Therefore, we need a *building* tool that can
automatically do the tedious work for us. Luckily, we may have a ton of
compilations, but they are very well structured thus having common procedures.
Therefore, writing the *descriptions* of compilation/linking is feasible and
should be easy.

An essential tool for building `C++`_ projects on Linux is ``make`` or
*makefiles*. It's hard to lecture everything of ``make`` since it is a very
large building framework. In addition, man-made makefiles become rare and rare.

For this section, we will learn through examples and try to understand some
essential components of ``make``, which will be used in future homework
assignments. If you are interested in ``make``, it's good to look at the
`official website of make <https://www.gnu.org/software/make/manual/make.html>`_.

Take a look at the :ziplec_5:`make_eg`.
