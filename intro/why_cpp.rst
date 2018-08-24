.. include:: ../links.txt
.. include:: ../roles.txt

.. _intro_why_cpp:

Why `C++`_?
===========

.. contents:: Table of Contents
   :local:
   :backlinks: top


You Should Consider Using `C++`_ If
-----------------------------------

The chances are that you may heard a lot of good things of `C++`_, and finally
you have decided to give it a shot. Great! There is not doubt with the power of
`C++`_. It is one of the most widely used programming languages, found in a
large range of applications. Unsurprisingly, `scientific computing` communities
use `C++`_ quite often in their projects. For instance, if you are interested
in solving `partial differential equations` (PDEs), then open-sourced
frameworks such as `OpenFOAM`_ and `SU2`_ might attract people who work in
`computational fluid dynamics` (CFD), and `FEniCS`_ and `deal.II`_ for
researchers who are interested in `finite element methods` (FEM) for solving,
say, structural problems. Of course, the `computational geometry algorithms
library` (`CGAL`_) is very popular for computer scientists who develop
geometry-based algorithms. What about for students who work in much lower level
research areas, such as developing numerical algorithms. No problem, `Eigen`_
has been around for awhile that supports efficient representations of
fundamental numerical computation objects, like vectors, matrices, and tensors.
OK, I think I can stop here!

Concepts that you learn from `C++`_ can be directly used in other programming
languages such as Java, `Python`_, `MATLAB`_, C, Fortran, etc. Personally,
I believe writing an algorithm in `C++`_ helps you fully understand
the idea and, potentially, can also improve the algorithm design. Let's say,
you probably has already learned how to do matrix multiplications in your
college linear algebra classes. Then, when your instructors asked you to
implement this as homework assignment in `MATLAB`_, what you did is probably
something like the following

.. code-block:: matlab

  A = rand(3);
  B = rand(3);
  C = A*B;

or in `Python`_

.. code-block:: python

  import numpy as np
  A = np.random.random((3,3))
  B = np.random.random((3,3))
  C = A.dot(B)

Well, I am kidding! This is cheating as homework assignments. You probably
implemented the triple for-loops. If you did a timing analysis, you would probably
see that the triple for-loop version is more than 100 times slower. Languages like
`Python`_ or `MATLAB`_ hide details from users, for instance, many students
don't understand how matrices are stored in `MATLAB`_ and `NumPY` and the
difference between accessing from column ``j`` to column ``j+1`` in these two
languages, i.e. speed is different when accessing :python:`A[i,j:j+2]` and
:matlab:`A(i,j:j+1)`. On the other side, `C++`_ hides nothing from users.

You Should **NOT** Consider Using `C++`_ If
-------------------------------------------

`Very well, so I should only code with C++!`

Wait, wait... There are many things that can simply be done with in 1 or 2
lines in `Python`_, but may take you hundreds of lines in `C++`_. Let's
still use the above matrix multiplication example. First, the concept of
matrices does not exist in **native** `C++`_, so you need define it. Once
you have the matrix *class* (future), you, of course, cannot expect that
`C++`_ is smart enough to automatically generate those linear algebra
operations for you, as a result, you need to implement them. Finally,
debugging your implementations will take a fairly amount of time.

In short, there are several situations that I think you should not consider
directly using `C++`_

"By the end of the day, all I want is something..."
+++++++++++++++++++++++++++++++++++++++++++++++++++

Well, with `C++`_, *"by the end of the day"*, you are still struggling with
software designs. Typically, it's not easy to get something working in `C++`_
as nicely as *high level* (future) programming languages in short terms.

"My project/research is still at infant stage, I wanna test some ideas."
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

`C++`_ is not a friendly language for developing algorithms... `MATLAB`_, for
example, is a great framework for developing numerical algorithms. As a matter
of fact, all SBU students can use it "freely" under its educational license.

.. note::
  This statement works for most students who study in typical applied math fields.
  However, for students majoring in *high performance computing* (HPC), stories
  are different.

"I'm confused..."
-----------------

"I am here to learn `C++`_, but it seems like I should not use it..."

Learning `C++`_ is always beneficial, even though you may not use it right
away! Personally, I believe learning `C++`_ can help you understand more
and be more professional in programming. For instance, if you program for
`Python`_ and Java, `C++`_ can help you understand more about their
*garbage collections* (GC). Also, *shadow copy* will no longer be an enemy
of you, because you know what's going on under the hood.

If you code for `MATLAB`_, `C++`_ can help you be aware of *pass by value*
(PBV), and how to avoid unnecessary data copying so that you can write more
efficient `MATLAB`_ scripts.

How To Read The Lecture
-----------------------

By "I", I mean myself. By "We", I mean the
`Department of Allied Mathematics & Statistics`_ (AMS) and/or
`Institute for Advanced Computational Science`_ (IACS). Also, it's worth
noting that this lecture note is mainly created for preparing the course,
and sharing some experiences in programming `C++`_. So I will use the informal
word "You" to address the students. Finally, the term `C++`_ implicitly
refer to *C++11* (see :ref:`intro_lec0_std`), for other versions, I will
address them explicitly.

`Sphinx`_ is really a great tool for writing this note. Here, I leverage
several nice directives to do highlighting.

**Tips**, used for giving some tips/tricks

.. tip:: :ref:`intro_lec0` is great place to start.

**Notes**, used for emphasis on technical points

.. note::
  My fundamental assumption is that you all are new to `C++`_ programming but
  with decent experiences in at least one of `Python`_, `MATLAB`_/`Octave`_, or
  Java.

**Warnings**, danger areas!

.. warning::
  Generally speaking, `C++`_ is not for someone who has no programming
  background.

Acknowledgments
---------------

I would like first to thank AMS and IACS for giving me this great
opportunity for teaching this course. Also, my supervisor,
`Prof. Jim Jiao <http://www.ams.sunysb.edu/~jiao/>`_, helps a lot in
sharing his experiences in teaching and setting up the Docker images.
