.. include:: ../links.txt
.. include:: ../roles.txt

.. _intro_lec0:

Lecture ZERO
============

.. contents:: Table of Contents
   :local:
   :backlinks: top

Comment! Please Comment...
--------------------------

All programming languages have their way to comment the source
codes. In `Python`_, people use number sign to start a line
of comment

.. code-block:: python

    # This is a comment
    # This is another comment

In `MATLAB`_, people use percentage sign, i.e.

.. code-block:: matlab

    % This is a comment
    %{
    This
    is
    a block of
    comments
    %}

In `C++`_, we use double forward slashes :cpp:`//` to comment, i.e.

.. code-block:: cpp

    // This is a c++ comment
    // Compiler will not read me!

Of course, the old C style comment is also valid, i.e.

.. code-block:: cpp

    /*
    compiler will
    not read
    anything
    in this
    block
    */

.. tip::
    For `C++`_, it's better to stick with :cpp:`//` even though you have
    multiple lines of comments.

**Comments make others life better.**

Imagine you join a research group and continue on some former member's work.
The only thing you get is his/her codes with no comments. Then, let's just
hope the codes are very robust and have no errors (99.99% chance no!).
Otherwise, it will waste you lots of time to figure out what he/she has done.

Also notice that, eventually, you will become someone's "former" member, so
do not let your academic litter brothers/sisters run into the same situation.

**"I'm so glad that I commented on this file nicely!"**
