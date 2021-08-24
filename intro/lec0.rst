.. include:: ../links.txt
.. include:: ../roles.txt

.. _intro_lec0:

Lecture Zero
============

.. contents:: Table of Contents
   :local:
   :backlinks: top

Comment! Please Comment...
--------------------------

All programming languages have their way to comment the source codes.
In `Python`_, people use hash tag to start a line of comment

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

In `C++`_, we use double forward slashes :code:`//` to comment, i.e.

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
    For `C++`_, it's better to stick with :code:`//` even though you have
    multiple lines of comments.

Making comments make others life better.
++++++++++++++++++++++++++++++++++++++++

Imagine you join a research group and continue on some former member's work.
The only thing you get is his/her codes without a single line of comments.
Then, let's just hope the codes are robust enough thus having no errors (99.99%
chance no!). Otherwise, it will waste you lots of time (sometimes can be a
whole semester) to figure out how to make the code run.

Also notice that, eventually, you will become someone's "former" member, so
do not make your academic litter brothers/sisters hate you.

"I'm so glad that I commented!"
+++++++++++++++++++++++++++++++

You are the one who benefits the most from making comments. While
doing research, an important thing that everybody needs to keep in mind is to
make the work reproducible. One needs to make sure that his/her results can be
reproduced in the future. Therefore, make comments for yourselves in the
future.

Of course, there are better tools, e.g. `Git`_ see :ref:`here <soft_req_git>`,
to help you manage your work. But making comments are the most fundamental
requirement that.

Good versus Bad Comments
+++++++++++++++++++++++++++++++
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

    The following information is based on personal experience, thus it is
    subjective.

Rule I: Make the variable names meaningful.
+++++++++++++++++++++++++++++++++++++++++++

Historically, people like to use ``foo``, ``bar``, or ``spam`` to demonstrate
ideas. Usually, they don't assume or know the backgrounds of the readers, so
they choose some `placeholder` names that can be replaced in real codes. Hence,
avoid using these names in your projects; no one wants to see placeholders in
the final products.

Another commonly used word is ``temp`` or ``tmp`` that stands for temporary
variables. Personally, I use this word only for some variables that have short
lifetime.

A rule of thumb is to ask your workmates and check whether they can understand
the meaning of your variables.

Rule II: Make the variable names compact.
+++++++++++++++++++++++++++++++++++++++++

Making things meaningful doesn't mean you have to be verbose. Also, don't
forget we have just learned how and why to make comments! Commonly, people
use abbreviations for their variable names, and this is what we shall follow.

.. tip::

    Choose an abbreviation that will appear in your project documentation or
    your papers/reports.

Rule III: Most functions should start with verbs.
+++++++++++++++++++++++++++++++++++++++++++++++++

This idea is commonly agreed by most of people, especially in scientific
programming.

.. tip::

    Some commonly used verbs: ``set``, ``get``, ``fetch``, ``extract``, ``is``,
    ``assign``, ``compute``, ``determine``, ``swap``, ``move``, ``init``,
    ``destroy``, ``create``, ``remove``, ``reset``, ``reserve``, ``put``,
    ``resize``, etc.

.. note::

    `C++`_ encourages people to hide `member variables` (future) and access
    them through `member functions` (future), e.g. ``size``, ``length``,
    ``data``, ``capacity``, etc.

Format Your Files
-----------------

Besides comment your codes, another important aspect is to have a nice layout
of your codes, so that it makes others who read your work enjoyable.

.. code-block:: cpp

    for(int a=0;a <10;  ++a) {
            foo[a] =1.0; bar[a]=2.0;
        spam[a]  =  3.0;}

vs.

.. code-block:: cpp

    for (int a = 0; a < 10; ++a) {
        foo[a]  = 1.0;
        bar[a]  = 2.0;
        spam[a] = 3.0;
    }

Well, I vote for the second one!

However, manually doing this is a pain. We shall leverage the automatic tool
such as `clang-format`_, which can be used through our editor (`vscode`_)
through the `Docker`_ image for this course.

.. _intro_lec0_std:

`C++`_ Standard
---------------

The first ISO `C++`_ standard was ratified in 1998, so that version is referred
as C++98. Later on, we got C++03. **The game changer is C++11**, which
introduced many unique features. Personally, I think C++11 is totally a
different language compared to its previous versions. For this course, all
materials are based on C++11, and the term `C++`_ is implicitly referred to
version 11, for instance, the following statement is correct under this
assumption: *In C++, you can use lambdas instead of functors*.

.. the following information might be outdated!

The current standard is C++17. However, in scientific computing, the truth is
that there usually exists a gap between current standard in practice and
current ISO standard. The good news is that most of open-sourced projects have
moved or are moving to C++11, it's safe to assume C++11 for audiences who are
interested in *scientific programming*. As a matter of fact, the first
feature-complete GCC was version 4.8.1 [#]_, which was released on May 31,
2013 [#]_. Also, our
`Seawulf <https://it.stonybrook.edu/help/kb/understanding-seawulf>`_
cluster's system GCC has version 4.8.5, which means it fully supports C++11.

.. [#] see `GCC C++ standard supports <https://gcc.gnu.org/projects/cxx-status.html>`_
.. [#] see `GCC release <https://gcc.gnu.org/releases.html>`_
