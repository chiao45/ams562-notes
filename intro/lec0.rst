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

Comments make others life better.
+++++++++++++++++++++++++++++++++

Imagine you join a research group and continue on some former member's work.
The only thing you get is his/her codes with no comments. Then, let's just
hope the codes are very robust and have no errors (99.99% chance no!).
Otherwise, it will waste you lots of time to figure out what he/she has done.

Also notice that, eventually, you will become someone's "former" member, so
do not let your academic litter brothers/sisters run into the same situation.

"I'm so glad that I commented on this file nicely!"
+++++++++++++++++++++++++++++++++++++++++++++++++++

Actually, you are the one who benefit the most from comments. While doing
research, an important thing that everybody needs to keep in mind is to make
the work reproducible. One needs to make sure that his/her results can be
reproduced in the future. Therefore, make comments for yourselves in the
future.

Of course, there are better tools, e.g. `Git`_, to help you manage your works.
But comments are the most fundamental requirement that you need to organize
yourselves nicely.

Let's take a look at the following examples:

.. code-block:: cpp

    // This function does blah blah ...
    // This is the core component in the algorithm of step 1 in my paper...
    // Essentially, this function is an extension of blah blah ...
    //
    // The following inputs arguments are needed:
    //  ...
    // This function returns an integer flag that indicates ...
    //
    // See Also
    //  compute_next, compute_final
    int compute_core(...) {
        // The first step is to ...
        ...
        // The second step is to ...
        ...
        // WARNING! The following codes assume ...
        ...
        // Finally clean up everything with ...
        ...
    }

vs.

.. code-block:: cpp

    // compute core function
    int compute_core(...) {
        ...
    }

Naming Conventions
------------------

Defining variable names is not a trivial task. There are some standard rules,
but for this class, I will briefly share some of my **personal** styles.

.. warning::

    The following information is based on personal experience thus it can be
    subjective.

Rule I:
