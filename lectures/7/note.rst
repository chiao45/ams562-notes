.. include:: ../../links.txt
.. include:: ../../roles.txt

.. _lec7:

.. contents:: Table of Contents
   :local:
   :depth: 1
   :backlinks: top

Introduction to ``template`` & *STL*
====================================

.. contents::
   :local:
   :backlinks: top

What are Templates?
-------------------

`template` is a unique concept of `C++`_; it allows to define certain templates
for the compiler so that the latter can generate the code for you on the fly.
Using template enables the ability of interacting with compiler in order to
fully optimize the code.

A `template` argument can be either a **type** or an
:ref:`integral object <lec1_builtin_int>`. It can be applied to both functions
and classes.

Using templates is just like defining functions, you need to provide a list
of *template arguments* with in angle brackets, i.e. ``<>``.

.. code-block:: cpp

    template<class T>
    void print(const T& obj) {
        std::cout << obj;
    }

The function above defines a template function that simply writes the unique
input argument, ``obj``, into ``cout`` streamer.

The "type" ``T`` is a template or placeholder that will be deduced by the
compiler during compilation. For instance, we can directly plugin any
:ref:`build-in types <lec1_builtin>` into the ``print`` function, because
we know the output operator is well-defined for them.

.. code-block:: cpp

    print(1);       // int
    print(2.0);     // double
    print(3.0f);    // float
    print(1L);      // long

During instantiation of the template types, the compiler *must* compile the
code on the fly, which guarantees a better performance.

**Question**, do the print statements above refer to the same function?

**NO**, each of them is derived from the template function ``print`` and then
customized with the specific type ``T``. In fact, the actual function types
are:

.. code-block:: cpp

    print<int>(1);
    print<double>(2.0);
    print<float>(3.0f);
    print<long>(1L);

So, the actual :ref:`function type <lec4_func_adv_type>` of the first print is
:code:`void(int)` with function name :code:`print<int>`.

Now, for user defined types, i.e. classes, as long as the
:ref:`output operator is overloaded <lec6_adv_class_io>`, we can directly
plug them in without any addition efforts. For instance, our
:ref:`complex number <lec6_adv_class_cmplx>` is a perfect example.

.. code-block:: cpp

    ComplexNumber a(1.0, 2.0);
    print(a);

because the output operator is overloaded for ``ComplexNumber``, the function
:code:`print<ComplexNumber>` just works out-of-box.

.. note::

    Templates are one of the most useful and powerful technique in practice.
    However, due to its complexity and the time limitation of this class, it's
    impossible to cover it in detail. For further reading, I recommend
    the book `C++ Templates - The Complete Guide, 2nd Edition <http://www.tmplbook.com/>`_
    as a wonderful offline learning material.

.. tip::

    Essentially, the existence of ``template`` can be viewed as two kinds of
    restaurants; the first one provides a menu of dishes, whereas the second
    one provides a list of template recipes with the ingredients and seasonings
    offered by the customers.

The *Standard Template Libraries* (STL)
---------------------------------------

One of the great success of using template is the *standard template libraries*
(STL). By using templates, STL allows you to plug your application data into
the standard programming framework, which provides you convenient yet robust
basic data structure *containers* and *algorithms* that are associated with
them.

In summary, STL contains three main components:

1. data containers,
2. object iterators, and
3. algorithms

Containers
+++++++++++

The idea of containers are derived from fundamental data structures in computer
science. For instance, an array is a collection of elements that are stored
contiguously in the memory. Each of the elements is associated with an unique
key that is the index corresponding to the array; the concept of array is
pretty much static, but what is unknown is the **elements**. They can be
anything, from as simple as numbers (e.g. ``int``, ``double``, etc.) or as
complicated as some user-defined ``struct`` or ``class``. With this
consideration and the power of templates, what we can have is to implement
an "abstract" interface that holds the concepts of the array, including
the data management and data manipulation, then have the user elements as
template arguments, so that whenever the user gives us his/her application
data, we can simply generate an array data structure that is optimized for
the application.

All containers share some common operations, such as ``pop``, ``insert``,
``push``, ``erase``, range-for-loop, etc. The actual uses may vary. STL
containers give you a standard yet powerful way to represent and manipulate
the data. Two most important features of why we should use STL containers are:

1.

    STL is very reliable, i.e. people all over the world use them and keep
    testing them on different systems.

2.

    STL is guaranteed to be portable, i.e. there is an obvious reason that is
    because of the tag---*standard*! All vendor implementations (GNU, Microsoft,
    Clang, Intel, etc) must stay with standard so that their implementations
    can be considered as standard. So if you use STL containers for your data,
    your code will run on Windows, Linux, UNIX, etc.

.. tip::

    With modern `C++`_ (after C++11), you should always consider using STL.

There are mainly two types of containers:

Sequential Containers
`````````````````````

- ``std::vector`` in ``<vector>``
    - dynamic array like container
    - most efficient and widely used container
    - insertion/deletion in the middle is expensive
    - popping/pushing from back is efficient (if you do it right)
    - constant data accessing

- ``std::list`` in ``<list>``
    - doubly linked list like container
    - data accessing is slow
    - efficient element insertion and deletion

- ``std::deque`` in ``<deque>``
    - doubly ended queue like container
    - roughly speaking, "vector" but supports adding/removing elements from both front and end

- ``std::forward_list`` in ``<forward_list>``
    - singly linked list like container
    - you can only walk through the list in one direction
    - slightly efficient memory usage compared to std::list
    - recall :ref:`the list example <lec3_stm_loop_struct>`

- ``std::array`` in ``<array>``
    - static array like container
    - does not support data adding and removing
    - ideal for small data on stack manipulation

.. note::

    The difference of ``std::vector`` and ``std::array`` essentially narrows
    down to the comparison between :ref:`dynamic arrays <lec2_dyn>` and
    :ref:`static arrays <lec1_array>`.

All sequential containers have the default interface:

.. code-block:: cpp

    std::vector<double> v;          // vector of doubles
    std::list<double> dl;           // list of doubles
    std::deque<double> dq;          // deque of doubles
    std::forward_list<double> fl;   // forward list of doubles

One exception is the :code:`std::array`, since it's static array internally,
we need to give the size as the template argument, which means the size must
be known during compilation.

.. code-block:: cpp

    std::array<double, 3> a3;   // array of double with 3 elements
    // conceptually, it's equiv to
    double a3_raw[3];

Associative Containers
``````````````````````

Some sorted data structures are implemented as well.

- ``std::set`` collection of unique keys
- ``std::map`` collection of unique key-value pairs
- ``std::multiset`` non-unique version of ``std::set``
- ``std::multimap`` non-unique version of ``std::map``

.. tip::

    For `Python`_ programmers, you can consider ``std::set`` is the Pythonic
    ``set`` and ``std::map`` for Pythonic ``dict``.

.. note::

    However, do note that the dictionary in `Python`_ is hashmap, whereas
    ``std::map`` is ordered by keys. The hashmap in `C++`_ is a container
    called `std::unordered_map <https://en.cppreference.com/w/cpp/container/unordered_map>`_.

**We will mainly focus on std::vector, since its the commonly used one in scientific programming.**

.. _lec7_itr:

Iterators
+++++++++

One of the major drawback of :ref:`pointers <lec2_ptr>` is that it exposes the
raw memory to you, and the standard :ref:`pointer arithmetic <lec3_ptr_arith>`
may become invalid in certain situations.

For example, for an array, the difference between its two pointers gives the
number of elements in between. However, the difference between two list's
pointers is meaningless.

With this in mind, `C++`_ defines a special concept---*iterators*, which are
associated with different containers.

.. note::

    *Iterators*, which are very much like pointers, behave almost the same
    as pointers do.

Conceptually, the main difference between pointers and iterators is that the
former directly point to the system memory, while the latter point to the
objects in the containers.

.. code-block:: cpp

    // for std::vector and and array
    itr++;  // move the iterator to next element in std::vector
    ptr++;  // move the address to the next one

    // for std::forward_list and our list
    itr++;  // move to next node in the std::forward_list
    ptr = ptr->next; // move to next node in memory
    // note that ptr++ give non sense output

All containers have the following two member functions implemented and
overloaded with constant member functions as well.

- ``begin``, get the iterator that points to the first element.
- ``end``, get the ending iterator indicator (one after the last element).

.. code-block:: cpp

    auto first = v.begin(); // assume some vector (or anything else)
    auto ending = v.end();
    // you can simply loop through it by
    for (auto itr = first; itr != ending; ++itr) {
        // do things with itr
        *itr; // dereference
        itr-> ...; access some contents.
        ...
    }

.. tip:: Use ``==`` and ``!=`` for iterators, just like pointers.

`C++`_ also provides unified interfaces for all iterators:

- ``std::advance``, advance an iterator **inplace** to certain positions.

.. code-block:: cpp

    // iter will points to the 4-th element from the current one
    std::advance(iter, 4);

- ``std::next``, get next iterator

.. code-block:: cpp

    // iter1 points to iter's next, iter unchanged
    auto iter1 = std::next(iter);
    // iter2 points to the second element from iter
    auto iter2 = std::next(iter, 2);

- ``std::prev``, the opposite of ``std::next``

- ``std::distance``, get the **signed number** of elements between two iterators

.. code-block:: cpp

    // n is the number of element between iter1 and iter2, w/o iter2
    int n = std::distance(iter1, iter2);

.. important::

    For the iterator of ``std::vector``, it literally behaves exactly the same
    as the underlying memory pointers. Therefore, **for what we are focusing on**,
    you can consider iterators and pointers are basically interchangeable.

Algorithms
++++++++++

Based on standardizing how to traverse containers, STL also implements a
collection of algorithms such as ``copy``, ``fill``, search, ``for_each``,
``max/min``, ``partition``, ``sort``, binary search, etc. Again, use these
whenever possible to reduce your developing time and increase the portability
and robustness of your code.

How To Get Start With STL
-------------------------

With what we have learned so far, it's great to check the online references
for the APIs of STL. The one I use is `cppreference <https://en.cppreference.com/w/>`_.
