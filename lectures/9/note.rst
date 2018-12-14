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

    The :code:`operator()` must be overloaded as **constant** member functions.

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

One of the drawback of using functors is that you need to explicitly create
a functor whenever you use them. This can be inconvenient and make you codes
messy due to too many classes.

As an alternative, modern `C++`_ encourages people using *lambdas* instead.
A `lambda <https://en.cppreference.com/w/cpp/language/lambda>`_ is an unnamed
function object capable of capturing other objects in scope. **Define lambdas
whenever you need them.**

.. code-block:: cpp

    // lambda syntax
    [captures](parameter list){function body}

Here, we show a simple example that how to convert a "hello world" function
into a lambda.

.. code-block:: cpp

    // function version

    #include <iostream>
    void hello_world() {
        std::cout << "Hello World!\n";
    }
    int main() {
        hello_world();
    }

    // lambda version

    #include <iostream>

    int main() {
        auto hello_world = [](){
            std::cout << "Hello World!\n";
        }; // semi-colon
        hello_world();
    }

As you can see, the lambda version doesn't require you to explicitly define
the function. Everything is local with lambda, which is a very nice feature
to have.

Captures
++++++++

Lambdas are just a modern look of traditional functors, with this been said,
it's important to know how to deal with captures. You have already learned that
captures can be done with functors be declare member objects inside the
functors. For lambdas, captures are handles within ``[]``.

1. ``=``, capture by values
2. ``&``, capture by references

.. code-block:: cpp
    :linenos:
    :emphasize-lines: 2-3

    const int a = 1;
    const auto print_xpa = [=](const int x) {
        std::cout << "x+a=" << x+a;
    };

    print_xpa(2); // 3
    print_xpa(3); // 4

In line 2, the ``=`` inside ``[]`` indicates that everything inside this lambda
that doesn't appear in its parameter list will be captured (copied) by value.
In line 3, the variable ``a``, which is not a parameter of lambda ``print_xpa``,
is **copied** inside the lambda. The equivalent version of functor is:

.. code-block:: cpp

    class XPA {
    public:
        XPA() = delete;
        XPA(const int a) : _a(a) {}
        // callable
        void operator()(const int x) const {
            std::cout << "x+a=" << x+_a;
        }
    private:
        const int _a; // not reference, copy the value
    };

    // inside main
    XPA print_xpa(1);
    print_xpa(2);
    print_xpa(3);

To capture objects by their references, we need to use ``&``.

.. code-block:: cpp
    :linenos:
    :emphasize-lines: 2

    int counter = 0;
    auto increment_counter = [&]() {++counter;};

    increment_counter();
    increment_counter();

    std::cout << "counter = " << counter; // 2

In line 2, we can see that ``counter`` is indicated to be passed in with its
reference inside ``increment_counter``, thus it can be modified. As a result,
after calling the lambda twice (line 4-5), the counter has been set to 2.

.. note::

    Since lambdas have no explicit types, we need to use ``auto`` and let the
    compiler deduce the types for us. There are difference between constant
    lambdas, i.e. defined with ``const auto``, and normal lambdas. The former
    cannot modify objects that are captured by their references.

Examples of using lambdas with algorithms:

.. code-block:: cpp

    std::vector<int> rand_vals = {...};
    // Note that C++ can automatically deduce the return type if you
    // have return inside lambdas
    std::sort(rand_vals.begin(), rand_vals.end(),
        [](const int lhs, const int rhs) {return lhs>rhs;});

    float avg;
    std::cout << "Enter average score: ";
    std::cin >> avg;
    std::vector<float> scores = {...}; // fill in the scores
    const int counts = std::count_if(scores.begin(), scores.end(),
        [=](const float score){return score > avg;});
    std::cout << "total # above " << avg << " is " << counts;

``for_each``
------------

For each is a fully black-box algorithm routine, which loop through a container
and apply a unary operation on each of its elements.

Basically, a ``std::for_each`` can be converted into a for-loop with iterators:

.. code-block:: cpp

    for (auto itr = v.begin(); itr != v.end(); ++itr)
        unary_op(*itr);

Now, the following loop is for printing all values of a vector:

.. code-block:: cpp

    std::vector<int> v = {...};

    for (auto itr = v.begin(); itr != v.end(); ++itr) {
        std::cout << *itr << '\n';
    }

can be converted into a black-box ``for_each``:

.. code-block:: cpp

    std::for_each(v.begin(), v.end(), [](const int &val){
        std::cout << v << '\n';
    });

Now, let's see a more complicated example, adding two vectors. This task is
easy to do with traditional for loop:

.. code-block:: cpp

    std::vector<int> a = {1,2,3}, b = {3,2,1}, c(3);
    // c=a+b

    // traditional for loop
    for (int i = 0; i < 3; ++i)
        c[i] = a[i]+b[i];

The difficulties for converting this for loop into an ``std::for_each`` call
are:

1. how to pass ``a`` and ``b`` into the lambda, and
2. how to handle the index ``i``.

For 1, we already know the solution---capture by references; for 2, we also
need to capture a reference of some index counter that is defined outside
of the lambda, and keep increment it inside the lambda.

.. code-block:: cpp

    int index = 0;
    // capture index, a, b into lambda
    auto add_ab = [&](int &current_c){
        current_c = a[index]+b[index];
        ++index; // increment index here
    };
    std::for_each(c.begin(), c.end(), add_ab);
    // Note that each of the element (int) is passed in as normal reference
    // and the key is that index goes with the same speed of for_each, thus
    // c and a+b are sync
