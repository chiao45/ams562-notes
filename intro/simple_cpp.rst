.. include:: ../links.txt
.. include:: ../roles.txt

.. _intro_simple_cpp:

Simple `C++`_
=============

.. contents:: Table of Contents
   :local:
   :backlinks: top

.. _intro_simple_cpp_main:

The ``main`` functions
----------------------

Each `C++`_ program is written in a ``main`` function in `C++`_, where a
``main`` function must return an integer to indicate your system the exit
status of the program.

.. note:: 0 is used for indicating exiting successfully.

Here is the simplest `C++`_ program, :code:`int main() { return 0; }`,
which does nothing but just returns ``EXIT_SUCCESS`` to your system.

Compile the one-line program
----------------------------

Unlike `Python`_ and `MATLAB`_, where you can directly run programs, all `C++`_
programs must be first **compiled** into executable binaries.

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
    path separator on Linux. To navigate toi a directory through terminal, you
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

.. code-block:: cpp
    :linenos:

    #include <iostream>

    int main() {
        std::cout << "Hello World!" << std::endl;
        return 0;
    }


Once we include the IO library (line 1), we can use the standard output
streamer, i.e. ``std::out``, to write out messages (line 4).

Now, copy the program into ``hello_world.cpp``, and compile and run it.

.. note::

    This section is basically to demonstrate some simple codes. There will be
    a specific section talking about IO.
