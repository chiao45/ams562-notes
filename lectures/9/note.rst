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

    bool unary_boolean(const T &);
    bool binary_boolean(const T &, const  T&);
    void unary_proc(T &); // NOTE that T here can be constant types

A perfect example would be using :code:`std::count_if`. Here, assuming I
have a students homework scores and I want to count the total number of
students whose scores are above 50.

.. code-block:: cpp

    // define unary operation, in this case, we can use function
    bool above50(const float score) { return score > 50.0f; }

    std::vector<float> scores = {...}; // fill in the scores
    const int counts = std::count_if(scores.begin(), scores.end(), above50);
    std::cout << "total # > 50 is " << counts;

The binary boolean operations can be used in :code:`std::sort`. The default
behavior is that given element ``a`` and ``b``, ``a`` goes before ``b`` if
``a`` is less (operator <) than ``b``. This can be overwrite by providing a
customized binary boolean operation with left-hand and right-hand sides, say
``lhs`` and ``rhs``, resp. Then ``lhs`` goes before ``rhs`` in the sorted order
if the binary operation returns ``true``.

.. code-block:: cpp

    // define the function
    bool greater(const int lhs, const int rhs) { return lhs > rhs; }

    // under main function
    // generate a random array
    std::vector<int> v = {...};

    std::sort(v.begin(), v.end(), greater);
    // now v is in descending order

.. note::

    The binary boolean operation must meet the requirement that if
    ``comp(lhs,rhs)`` returns ``true``, then ``comp(rhs,lhs)`` must be
    ``false``.

Functors
--------

There are many drawbacks of using traditional functions as operations inside
algorithm routines. One of the obvious one is that it's not easy to capture
external data into the function.

For example, for the counting averaging example, what if we want to count
students store that is greater than :math:`\alpha`, where :math:`\alpha` can't
be determined beforehand?

.. code-block:: cpp

    bool greater2(const float score) {
    // we cannot add alpha into the function interface, because that will
    // change the API thus resulting a non-unary operation
        return score > alpha; // how to plug in alpha???
    }

The problem can be easily solved by using the so-called *functors* in `C++`_.
*Functors* are function objects that overload the :code:`operator()`, so that
it mimics the behavior of functions.

.. code-block:: cpp
    :emphasize-lines: 8-11

    class AboveAvg {
    public: // must be public!
        // don't allow default construction
        AboveAvg() = delete;
        // constructor to plug in the default score
        explicit AboveAvg(float avg) : _avg(avg) {}

        // operator() overloaded as "unary" operation
        bool operator()(const float score) const {
            return score > _avg;
        }
    private:
        float _avg;
    };

.. note::

    The :code:`operator()` must be overloaded as **constant** member funcitons.

.. code-block:: cpp

    // inside main function
    float avg;
    std::cout << "Enter average score: ";
    std::cin >> avg;
    AboveAvg abv_avg(avg);
    std::vector<float> scores = {...}; // fill in the scores
    const int counts = std::count_if(scores.begin(), scores.end(), abv_avg);
    std::cout << "total # above " << avg << " is " << counts;

Lambdas
-------

``for_each``
------------
