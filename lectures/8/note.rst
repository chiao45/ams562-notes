.. include:: ../../links.txt
.. include:: ../../roles.txt

.. _lec8:

.. contents:: Table of Contents
   :local:
   :depth: 1
   :backlinks: top

Using ``<vector>`` in STL
=========================

.. contents::
   :local:
   :backlinks: top

:code:`std::vector` is the most widely used container in STL. The reason is
simple, i.e. because arrays can always give you better performance due to the
compact memory layout.

.. tip::

    In our Jupyter notebook, type ``?std::vector`` will bring you to the
    `cppreference page <https://en.cppreference.com/w/cpp/container/vector>`_
    of STL vector.

Unlike the "vector" we have seen in previous homework and project assignments,
STL vector is a :ref:`template implementation <lec7>`, thus it is not
restricting to ``double`` (what we have). Generally speaking, the contained
data type usually comes from different applications, which are, typically, not
as simple as :ref:`the built-in types <lec1_builtin>`.

.. code-block:: cpp

    namespace std {
        template<class T>
        vector;
    }

You can consider the STL vector has the interface above.

For the commonly used member function interfaces, please look at the
cppreference page referred above.

.. code-block:: cpp

    #include <vector>

    int main() {
        std::vector<int> a(10);
        for (int i = 0; i < 10; ++i) {
            a[i] = i+1;
        }
    }

With STL containers, no more dynamic memory management!

Traversing ``vector``
---------------------

Looping through :code:`std::vector` is flexible, you can stick with the old
school fashion, i.e. indices and operator ``[]``. In addition, you have the
following options:

Using Iterator
++++++++++++++

One of the standard way nowadays to loop through vectors is to use
:ref:`iterators <lec7_itr>`.

.. note::

    For ``vector``, you can consider that its iterators are nothing but just
    pointers. More detailed speaking, the normal iterators, i.e.
    :code:`std::vector::iterator` is the normal pointer, while the
    :code:`std::vector::const_iterator` maps to the *pointer to constant*.

.. code-block:: cpp

    // given a vector v of integers
    for (std::vector<int>::iterator itr = v.begin(); itr != v.end(); ++itr)
        *itr = 1;
    // "dereference" the iterator and assign the value to 1
    for (std::vector<int>::const_iterator itr=v.begin(); itr!=v.end(); ++itr)
        std::cout << *itr;
    // cout the content with constant iterator

However, it's sometimes really annoying to write the iterator types, we can use
``auto`` and let the compiler deduce the type for use automatically.

.. code-block:: cpp

    for (auto itr = v.begin(); itr != v.end(); ++itr)
        *itr = 1; // itr is normal iterator
    for (auto itr = v.begin(); itr != v.end(); ++itr)
        std::cout << *itr;

.. note::

    `C++`_ has introduced ``auto`` since C++11. It is convenient to use
    especially when the type names are wordy. However, at the same time, you
    may make your codes hard to read, given the fact that `C++`_ codes are
    hard to understand already.

Using The *Range-for* Loop
++++++++++++++++++++++++++

The *range-for* loop comes with iterators (explained briefly later). It mimics
the `Python`_ range-based loops.

.. code-block:: python

    a = [10+i for i in some_list]
    for val in some_list:
        print(val)

Range-for loop hides the indices (since sometimes we really don't need them)
and directly accesses the contents in sequential order.

In `C++`_ (after C++11), the range-based for loop reads:

.. code-block:: cpp

    for ([type] val: [container])
        // do work with val

Where ``type`` is the the type of elements that are contained in ``container``.

.. code-block:: cpp

    // again, assume we have an integer vector v
    for (int val:v) {
        std::cout << val;
    }

The code above loops through ``v`` by its values. You can, of course, loop
through it with reference.

.. code-block:: cpp

    for (int &val:v) {
        val = 1;
    }

Now, all elements in ``v`` are assigned with value 1.

.. tip::

    Using *ranged-for* loop sometimes make your code more readable to people
    who come from high level programming languages.

The Bottom Line
+++++++++++++++

**Use whatever you are comfortable with!** In addition, choose one over another
one based on difference situations; for instance, if you have too many vectors
that need to be looped at once (with potentially difference indices), then
using traditional way may be messy. However, for simple tasks, using indices
makes the codes straightforward and easy to read.

**Understanding iterators is important** since iterators are not only used in
looping.

Checkout the :nblec_7:`vector_intro`.

Adding/Removing Elements
------------------------

One of the major advantage of using containers is to management data
dynamically; this includes the following operations:

1. ``insert``, add new elements in random positions,
2. ``erase``, remove elements in random positions,
3. ``clear``, destroy all elements at once,
4. ``push_back``, add a new element to the end, and
5. ``pop_back``, remove the last element.

To insert or remove elements, you need to pass in the iterators that indicate
the positions.

See this :nblec_7:`vector_elemmani`.

Using Vector Efficiently
------------------------

.. warning::

    Although :code:`std::vector` provides you the flexibility in managing the
    contents, you should not always use them without proper understanding of
    what actually happens under the hood.

The first concern is data movement due to adding and inserting elements in the
middle of arrays. These options require :math:`O(n)` complexity thus should be
avoided. If you find out that ``insert`` and ``remove`` are highly needed for
your application, then ``vector`` is not the right container for you.

Nest, we need to under stand how :code:`std::vector` manages the internal
database.

Each vector has two sizes that associated with the data size: 1) capacity, i.e.
the storage allocated and currently available to use, and 2) size, i.e. the
actual storage is in-used.

.. note:: ``size`` is no larger than ``capacity``.

The capacity information can be queried by the member function
:code:`std::vector::capacity`.

Please look at the :nblec_7:`vector_size`, which explains the size and capacity
in detail.

For problem sizes are known, then allocating enough storage at the beginning
is the way to go. If the problem sizes are not known beforehand, then try to
estimate a reasonable upper bound and using `push_back` to construct the
vectors incrementally.

.. note:: Call :code:`std::vector::reserve` to reserve capacity.

.. note::

    STL guarantees that even starting with a **real** empty vector, pushing
    back always results *amortized* constant time complexity. But it's good
    exercise to pre-allocate the vector, especially for relatively small
    problems.
