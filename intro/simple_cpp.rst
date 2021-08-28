.. include:: ../links.txt
.. include:: ../roles.txt

.. _intro_simple_cpp:

Simple `C++`_
=======================

Here, we will present the most basic C++ program that does something.
The purpose of this section is to

* Give you a chance to use the programming environment
* Give a first feel of how you control the computer using C++. 

.. contents:: Table of Contents
   :local:
   :backlinks: top

.. _intro_simple_cpp_main:

The simplest `C++`_ program
-------------------------------

Here is the simplest `C++`_ program you can write.

.. code-block:: cpp

    int main() {return 0;}

Every `C++`_ program must have a function ``main``.  
A function is a named sequence of instructions that the computer executes.
Each function has four parts:

1. A *return* type `int`, specificies the kind of result
2. A *name*, ``main``
3. A *parameter list* ``()``
4. A *function body* enclosed in the set of curly braces ``{}``, lists the sequence of statements

The ``main`` function must return an integer to indicate your system the exit
status of the program.  




.. note:: 0 is used for indicating exiting successfully.

.. _intro_simple_cpp_compile:

Compile and link the one-line program
---------------------------------------------

Unlike `Python`_ and `MATLAB`_, where you can directly invoke the scripts, all
`C++`_ programs must be first **compiled** into executable binaries.
By compiling a program, we mean translating the human-readable text instructions
into something that the computer can execute.  
In this class, we use the g++ compiler to 
translate our source code into executable file.  

.. note::

    The compilation stage is one of the key reason why static languages are
    faster than dynamic languages.

Now, copy the one line program into a file with name ``simple.cpp``, inside
a terminal, invoke:

.. code-block:: console

    $ g++ simple.cpp

This by default will compile the program into an executable file called
``a.out`` that lies in the same directory. To run the program, type:

.. code-block:: console

    $ ./a.out

.. tip::

    ``./`` in front of the executable means the file is under *current working
    directory* (cwd). You can type ``pwd`` in the terminal to check *cwd*.
    In general, ``.`` means current, ``..`` means previous, and ``/`` is the
    path separator on Linux. To navigate to a directory through terminal, you
    need to use the built-in command ``cd``, which stands for *change
    directory*. For instance, if I want to go to previous directory, I can
    simply type ``cd ..``. ``cd ./foo`` will bring me to the ``foo`` folder
    that locates at *cwd* (you can omit ``./`` in this case). Absolute path can
    also be used. For example, ``cd /path/to/my-homework`` will navigate to
    ``/path/to/my-homework``, and the leading ``/`` on Linux means the root
    directory.

Of course, this program seemingly does nothing. To check the returned code,
type ``echo $?``, which will gives you the exit-code of most recent program.
You should see ``0`` on the screen.

"Hello World!"
--------------
Here we will introduce the classic "Hello World!" program written in C++.
Unfortunately, you cannot write one line code for "Hello World!" in `C++`_. In
`Python`_, you can write a ``hello_world.py`` script with:

.. _intro_py_hw:

.. code-block:: python

    print('Hello World!')

And simply type:

.. code-block:: console

    $ python3 hello_world.py

You should see "Hello World!" on your screen. Or even something like:

.. code-block:: console

    $ python3 -c "print('Hello World!')"

However, there is no built-in ``print`` method in `C++`_, we have to include
the standard input and output library, i.e. ``iostream``.

Here is the classic "Hello World!" program.

.. code-block:: cpp
    :linenos:

    // This program outpouts the message "Hello, World!" to the monitor
    #include <iostream> // #include directive

    int main() {// C++ programs start by executing the main function
        std::cout << "Hello World!\n";// output "Hello, World!"
        return 0;
        // notice that semicolons terminate statements. 
    }
    // quotes delimit a string literal
    // \n is notation for new line

Let's parse some of this program

* ``#include <iostream>`` The include directive.  This is where we  included the definition of ``std::cout``
* ``std::cout`` character output stream
* ``"Hello World!\n`` String literal that is displayed on screen
* ``// This is a comment``




Now, copy the program into ``hello_world.cpp``, and compile and run it.

.. note::

    It's important you mind the details when writing programs in CPP.
    Try making a mistake and see how the compliler responds 

    * Forget the header
    * Forget to terminate the string
    * Misspell returned
    * Forget a semicolon
    * Forget a {

The hello world program is crucial because it represents the most basic program that you can write.
Its purpose is to get you familiar with writing programs in C++.
The rest of your programs should include the same basic structure.
In future lectures we will go over more information about I/O in C++


