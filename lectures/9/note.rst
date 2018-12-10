.. include:: ../../links.txt
.. include:: ../../roles.txt

.. _lec9:

.. contents:: Table of Contents
   :local:
   :depth: 1
   :backlinks: top

Using ``<algorithm>``
=====================

.. contents::
   :local:
   :backlinks: top

The ``<algorithm>`` library implements many fundamental algorithms in computer
science; they can be used as the building bricks for different applications.

.. note::

    All algorithms require iterators and return (if any) iterators. For
    :ref:`vectors <lec8>`, iterators are just pointers.

.. tip::

    I highly recommend you all look at `the cppreference page for algorithm <https://en.cppreference.com/w/cpp/algorithm>`_,
    it is clear and easy to read. Most importantly, it provides you with the
    "possible implementations" and complexity analysis so that it's easy to
    know what happens under the hood. It's worth noting that "possible
    implementations" are, of course, not actual implementations in, say, GCC,
    but they are logically identical to each other.

Getting Start with ``copy`` & ``fill``
---------------------------------------

Let's start with some easy examples, e.g. copy two containers and fill a
uniform value to the elements in a container.

.. code-block:: cpp

    #include <algorithm>
    #include <vector>

    // in main
    std::vector<int> src = {1, 2, 3};
    std::vector<int> tgt(3);
    std::copy(src.begin(), src.end(), tgt.begin());

    // copy values from src begin to src end to tgt with starting
    // iterator tgt.begin()
    // tgt = {1, 2, 3}

The interface is generic, which means it is applicable to not only ``vector``
but other containers.

.. code-block:: cpp

    #include <list>
    #include <vector>
    #include <algorithm>

    // in main
    std::list<int> src = {1,2,3};
    // since we have using a list, we know that the memory layout is
    // not compact
    std::vector<int> tgt(3);
    std::copy(src.begin(), src.end(), tgt.begin());
    // tgt = {1,2,3}

Similarly, we can use :code:`std::fill` to fill a container with a uniform
value.

.. code-block:: cpp

    std::vector<double> data(10);
    std::fill(data.begin(), data.end(), 1.0);
    // data = 1

.. note::

    Most algorithms return the destination iterators, thus you can use it
    recursively.

.. code-block:: cpp

    // concentrate two vectors into one
    std::vector<int> v1(2), v2(4);
    std::vector<int> v(6);
    std::copy(
        v2.begin(), v2.end(),  // the second part
        std::copy(v1.begin(), v1.end(), v.begin());

    // on return v = {v1 v2}

.. tip::

    :code:`std::copy_n` and :code:`fill_n` become handy if you know how many
    elements you need to deal with.

See this :nblec_9:`alg_simple`.

``sort``
--------

STL has a standard, i.e. :math:`O(n \log{n})`, sorting implemented in
``<algorithm>``. Using it is straightforward:

.. code-block:: cpp

    std::vector<int> v = {...}; // fill in the values
    std::sort(v.begin(), v.end());
    // done!
    // now v is sorted in ascending order

Now, let's take a closer look and see what happens under the hood. First, we
need to understand what are needed in sorting algorithms: 1) comparison, i.e.
:code:`operator<` and 2) swap, exchange two elements. ``int``, as a built-in
type, natively supports these requirements.

If the contained type, i.e. ``T``, is not as simple as ``int``, then you need
to ensure these two requirements.

.. note::

    The requirement of ``swap`` is called `ValueSwappable <https://en.cppreference.com/w/cpp/named_req/ValueSwappable>`_.

It's always a good practice to have a ``swap`` member function and a free
version **under the same namespace** for your data type (they may not be needed,
but will save you a lot when you need them, especially for fulfilling some
implicit requirements). For instance,

.. code-block:: cpp

    struct Student {
        int id;
        std::string name;
        void swap(Student &other) {
            std::swap(id, other.id);
            std::swap(name, other.name);
            // NOTE that swap is implemented under algorithm
        }
    };
    // free version
    void swap(Student &l, Student &r) { l.swap(r); }

    // Now, in order to sort Students, we need <
    bool operator<(const Student &l, const Student &r) {
        return l.id<r.id;
    }

See this :nblec_9:`sort` for running examples.

**Question:** How to sort the contents in descending order?

Algorithms with Customized Operations
-------------------------------------

STL allows you to pass in callable objects into certain algorithm routines so
that you can easily extend the functionality of STL algorithms.

Commonly used operations are:

1. unary boolean operations
2. binary boolean operations
3. processing unary operations

.. note::

    `C++`_ only requires the user-defined "operations" are *callable*!

Their corresponding interfaces:

.. code-block:: cpp


    

Functors
--------

Lambdas
-------

``for_each``
------------
