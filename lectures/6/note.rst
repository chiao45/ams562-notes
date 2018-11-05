.. include:: ../../links.txt
.. include:: ../../roles.txt

.. _lec6:

.. contents:: Table of Contents
   :local:
   :depth: 1
   :backlinks: top


.. _lec6_class_intro:

Introducing *Object-Oriented Programming* (OOP), ``class``
==========================================================

.. contents::
   :local:
   :backlinks: top

One of the main different between C and `C++`_ is that the latter is an
*object-oriented programming* (OOP) language, which means models are organized
around *objects* instead of *actions*. Traditionally, programs are done in a
way such that data and actions are separated and allocating data is easy but
defining the complex actions on top of it is hard.

The fact is that objects are what we care about, instead of arbitrarily data.
For instance, each of the student has a unique school ID, which can be
represented as an integer or a string. However, such a raw data type has no
meaning on its own thus useless; the "ID" data only becomes meaningful when
it couples with the corresponding student, which can be viewed as an
``object``.

In OOP, an ``object`` is a user-defined model that can contain both data (
a.k.a. fields/attributes/members) and code (a.k.a. methods/member functions).

.. note::

    One of the nice feature of OOP is that it allows people to fit the
    programming language into their problems.

The data and code usually are only applicable to the object itself and this
makes the programming cleaner and nicer.

The Basis
---------

Personally, the first step of doing OOP in `C++`_ is to think through your
problems and structure the design of objects. (This is the most challenging
part in OOP!)

For instance, let's keep thinking of the example of ``Student``. Each student
has:

1. a name: first/last and (or) middle names,
2. sex: male, female, or other,
3. type: undergraduate, master, or doctoral,
4. status: in what year is this student in, and
5. ID number.

These will be the members of ``Student``, and their corresponding data types
are:

1. name: ``std::string``,
2. sex: ``int`` or ``std::string``,
3. type: ``int`` or ``std::string``,
4. status: ``int`` or ``std::string``, and
5. ID number: ``int`` or ``std::string``.

Now, let's group everything into a ``class``, which is conceptually and
syntactically close to :ref:`struct <lec3_stm_loop_struct>`.

.. code-block:: cpp

    class Student {
        std::string name;
        std::string sex;
        std::string type;
        std::string status;
        long id;
    }; // semi-colon

Now, we want to create a student named Joe Chang.

.. code-block:: cpp

    Student joe;
    joe.name = "Joe Chang"; // ERROR!

However, this will not work, the following error will be thrown:

    error: 'std::__cxx11::string Student::name' is private within this context

The reason is that we don't have "permission" to access the ``name`` member in
``Student`` due to "incorrect" *accessing specifiers*.

In `C++`_, each content of a ``class`` object is associated with one of the
following accessing specifiers: ``public``, ``private``, and ``protected``
(future).

``public`` Access
+++++++++++++++++

A public access of a member or a member method is to allow it to be used from
outside of a class by any other functions/classes. To make the above example
work, we can simply do:

.. code-block:: cpp

    class Student {
    public:
        std::string name;
        std::string sex;
        std::string type;
        std::string status;
        long id;
    }; // semi-colon

Then, all of ``name``, ``sex``, ``type``, ``status``, and ``id`` are exposed
to outside thus modifying their values is valid.

.. code-block:: cpp

    Student joe;
    joe.name = "Joe Chang"; // Okay

.. note::

    ``struct``, by default, grants all its contents with ``public`` accessing
    permission.

``private`` Access
++++++++++++++++++

In contract to ``public`` accessing, contents with ``private`` accessing
specifier only allows to be accessed inside the class. By "inside", it means
that a ``private`` member can be only modified by other member functions.

.. note:: By default, all contents in a ``class`` are ``private``.

Remarks Regarding ``public`` & ``private``
++++++++++++++++++++++++++++++++++++++++++

Typically, `C++`_ prefers to have all data attributes under ``private``
specifier and modify them through ``public`` member functions (later). To
distinguish between ``public`` and ``private`` contents, usually, people
define some consistent naming schemes of the variables.

.. tip::

    Personally, I like to either append an "_" either in front of or at the
    end of ``private`` members.

.. code-block:: cpp

    class Student {
    private:
        std::string _name;  // append front _ to indicate private
    };

.. _lec6_basis_con_de:

Constructors & Destructors
++++++++++++++++++++++++++

When we create an object, the object's *constructors* will be called. And when
the object reaches its end of life, `C++`_ provides a mechanism called
*destructor* that will be invoked. `C++`_ generates a *default constructor*,
a *copy constructor* and a *destructor* for every class been defined.

.. note::

    The reason of the existence of the former two is that, by default, `C++`_
    must guarantee every user-defined object can be constructed and copied.

You can, of course, overwrite the three class "built-ins".

.. code-block:: cpp

    class Student {
    public:
        // default constructor
        Student() {
            // if you don't define this, then all the
            // members will have default values of string
            // and long
            name = "NA";
            id = -1;
        }

        // copy constructor
        Student(const Student &other) {
            // by default, it this is not given, then
            // all attributes will copy the corresponding entries
            // in "other".
            id = other.id;
            name = other.name;
            sex = other.sex;
            type = other.type;
            status = other.status;
        }

        // destructor
        ~Student() {
            std::cout << "destructor called!\n"
        }

        std::string name;
        std::string sex;
        std::string type;
        std::string status;
        long id;
    };

Some remarks:

1.
    Constructors are "member function" like except that the function name must
    be the object name and there is no return type.

2.
    Destructors are also function-like w/o return types, in addition, a prefix
    ``~`` must be written.

.. code-block:: cpp

    {
        Student joe;
        // what is the following output
        std::cout << joe.name << ':' << joe.id << '\n';

        joe.id = 123;
        joe.sex = "male";
        joe.type = "master";
        joe.status= "G1";

        Student joe_copy(joe); // invoke copy constructor

        // what about this?
        std::cout << joe_copy.type << ':' << joe_copy.status << '\n';
    } // destructor called here!

To better understanding constructors and destructors, I **strongly** encourage
you look at the :nblec_6:`constr-destr`.

More on Constructors
++++++++++++++++++++

Of course, you are not limited on only have the default and copy constructors,
to write your own constructors of an object, the following two rules, of which
you need to keep in mind:

1. Defining constructors is like defining functions **without** return types.
2. The "function" name must be the name of the object.

The rest are just parameter list that you want to enable to the object
construction interface.

.. code-block:: cpp

    class Student {
    public:
        // constructor with student name
        Student(const std::string &nm) {
            name = nm;
        }

        // constructor with student name and ID
        Student(const std::string &nm, long ID) {
            name = nm;
            id = ID;
        }

        // constructor with all information
        Student(const std::string &nm,
                const std::string &s,
                const std::string &tp,
                const std::string &st,
                long ID) {
            name = nm;
            sex = s;
            type = tp;
            status = st;
            id = ID;
        }

        std::string name;
        std::string sex;
        std::string type;
        std::string status;
        long id;
    };

Then, in the main program, you can use these constructors as:

.. code-block:: cpp

    Student s1; // default constructor
    Student s2("Jane"); // constructor with name
    Student s3("Chow", 1220033); // constructor with name and ID
    Student s3_cp(s3); // copy constructor
    Student s4("Mike",
               "male",
               "master",
               "G1",
               1234567890); // the "complete" version

Implicit Construction
`````````````````````

For **single** parameter constructors, by default, `C++`_ assumes the
constructors are *implicit* meaning that the object can be constructed by
converting from the single input parameter. In the ``Student`` example, the
constructor with only name parameter is implicit.

.. code-block:: cpp

    Student se("Foo Bar"); // explicit construction
    Student si = "Spam Eggs"; // implicit construction

If we use parentheses, the construction is explicit, the assignment is for
implicit construction. Well, you may feel like this is not important, since
it makes you feel like it's just a way how people prefer to construct objects.
However, the critical difference is
:ref:`function argument passing <lec4_func_pass>`.

.. code-block:: cpp

    // an demo interface function that takes student as input
    void interface(const Student &stdt) {
        std::cout << stdt.name << std::endl;
    }

As you can see, the function takes a ``Student`` as input, but because of the
conversion between ``std::string`` and ``Student`` is given by the implicit
construction process through ``Student::Student(const std::string &nm)``,
this function can also takes ``std:string`` as input!

.. code-block:: cpp

    Student s("Foo Bar");
    interface(s);

    // This is also allowed! The reason is that the input string
    // "Spam Eggs" will be implicitly converted to a Student object.
    interface("Spam Eggs");

Explicit Construction
`````````````````````

There is not really an answer to whether allowing implicit constructor is good
or not. In certain cases, it's nice and provide users a more flexible
constructor interfaces. However, at the same time, it's hard to debug the code.

`C++`_, with this consideration, provides a keyword ``explicit`` so that the
implicit-ness of a constructor can be disabled.

.. code-block:: cpp

    class Student {
    public:
        // explicit constructor with student name
        explicit Student(const std::string &nm) {
            name = nm;
        }
        ... // data members
    };

Now, if you try to call the ``interface`` function with a string input, you
will get a compilation error.

.. code-block:: cpp

    // interface("Spam Eggs"); // ERROR! string cannot be converted to Student

To have a better understanding of explicit/implicit constructors, please look
at :nblec_6:`imp_ex`.

Member Functions
++++++++++++++++

As we have already mentioned, an object in OOP language is not limited to only
hold data attributes, it can also contain code or, in other words, member
functions, which are a group of functions that only work for this type of
objects.

The ``this`` Pointer
````````````````````

We have already seen functions like:

.. code-block:: cpp

    struct MyStruct {...};
    void method(const MyStruct &obj, ...); // method for accessing obj
    void method(MyStruct &obj, ...); // method for modifying obj

.. note:: The function ``method`` above is overloaded.

Conceptually, this kind of functions are considered to be "member functions"
of ``MyStruct`` because it can only work for ``MyStruct``. With `C++`_ classes,
you can define member functions inside the class definition (just like data
attributes, which we have seen previously). Let's look at the following
example:

.. code-block:: cpp

    class MyClass {
    public:
    void method();
    };

To call it, just access the member functions like data attributes:

.. code-block:: cpp

    MyClass obj;
    obj.method();

**Question: how many input argument(s) does method have?**

Well, intuitively, you may say zero, and this is what we have learned in the
:ref:`function <lec4>` lecture. However, the correct answer is **one**.

If the input is zero, how does ``method`` know that it belongs to
``MyClass`` ;). What happens under the hood is that for each of the member
functions, a ``this`` pointer is passed in as the actual first input argument.
The ``this`` pointer has type of the object, in this case ``MyClass``.

.. note::

    For those who come from `Python`_, ``this`` == ``self``. The only
    difference is that ``this`` is transparent.

Personally, I suggest that to better understanding member functions, let's
Introduce a concept called *generic member function interface*. The ``method``
function has a generic interface of:

.. code-block:: cpp

    // Notice that no constant qualifier
    void MyClass::method(MyClass *this);

.. warning::

    The generic interfaces are just for demonstrations purpose, they are not
    legal `C++`_ syntax!

Now, let's convert the following member functions to their generic interfaces.

.. code-block:: cpp

    class MyClass {
    public:
    void set_value() {
        // we can explicitly use this to access a
        this->_a = 0;
    }
    // overload!
    void set_value(int a) {
        // we can omit this, which is typically
        // what ppl do in practice
        _a = a;
    }
    void copy(const MyClass &other) {
        _a = other._a; // within class definition, we can access _a!
    }

    private:
    int _a; // give some data for demo
    };

Remarks:

1.
    Now, you should understand that the meaning of ``private`` accessing.
    ``_a`` can only be accessed by ``MyClass`` during defining the
    interfaces.

2.
    Because of using ``this`` is optional, we have a "convention" that to
    use special pattern to indicate private data attributes.

The corresponding generic interfaces (not legal `C++`_ syntax!) are:

.. code-block:: cpp

    void MyClass::set_value(MyClass *this) {
        this->_a = 0;
    }
    void MyClass::set_value(MyClass *this, int a) {
        this->_a = a;
    }
    void MyClass::copy(MyClass *this, const MyClass &other) {
        this->_a = other._a;
    }

.. note::

    Like ``private`` data attributes, you can also have ``private`` member
    functions.

``const`` Member Functions
``````````````````````````

All the member functions we have defined so far can be only used without
``const`` qualifier.

.. code-block:: cpp

    void call_myClass(const MyClass &obj) {
        // ERROR! because set_value passes MyClass * in
        // not const MyClass *
        // and the const qualifier applied to obj will
        // automatically affect all its member functions/attributes
        obj.set_value();
    }

Intuitively, we know that the generic interface of member function with
``const this`` should be:

.. code-block:: cpp

    void MyClass::method(const MyClass *this, ...);

This is correct, but how to indicate that ``this`` has ``const`` qualifier?
`C++`_ requires you to append ``const`` to the end of any member functions to
indicate that these member functions use ``const this``; member functions with
``const this`` are referred as *constant member functions*.

.. code-block:: cpp
    :linenos:

    class MyClass {
    public:
        ... // set methods
        // typically, get method should have constant qualifier
        int get_value() const {
            // or this->_a
            return _a;
        }
    private:
        int _a;
    };

The ``const`` qualifier in line 4 indicates that the first input argument of
``get_value`` is ``const MyClass *this``.

.. tip::

    The general rules can be also applied here, i.e. use ``const`` whenever
    possible for member functions.

.. code-block::

    void print(const MyClass &obj) {
        std::cout << obj.get_value();
    }
    MyClass obj;
    obj.set_value(100);
    print(obj);

If ``get_value`` is not constant member function, the we cannot call it inside
the ``print`` *free function*.

.. note::

    *free functions* are simply not member functions, i.e. they belong to
    no specific classes.

Defining Member Functions
`````````````````````````

To separate the interfaces and implementations, we need to know how to define
constructors, destructors, and member functions outside of the class.

.. code-block:: cpp

    // in MyClass.hpp

    // we only declare the member functions
    // inside the class definition
    class MyClass {
    public:
        // explicit constructor
        explicit MyClass(int a);

        // set value
        void set_value(int a);

        // get value
        int get_value() const;
    private:
        int _a;
    };

To define these functions and the constructor, we need to indicate `C++`_ that
these methods are not *free*, they belong to ``MyClass``. We need to use
the scope accessor operator :code:`::` (we have seen this in ``namespace``).

.. code-block:: cpp

    // in MyClass.cpp

    #include "MyClass.hpp"

    // explicit can only be used inside class!
    MyClass::MyClass(int a) {
        _a = a;
        // or this->_a = a;
    }

    void MyClass::set_value(int a) {
        _a = a;
    }

    void MyClass::get_value() const {
        return _a;
    }

.. warning:: ``explicit`` can only be specified inside class definition!


The ``ComplexNumber`` Class
+++++++++++++++++++++++++++

Let's define a complex number class by using all the techniques we have learned
so far. First a complex number associates with a real and an imaginary
components thus the class data attributes should only have two floating
numbers.

.. code-block:: cpp
    :linenos:
    :emphasize-lines: 3

    class ComplexNumber {
    private:
        double _real, _imag; // real and imaginary parts
    };

Now, we want to overwrite the :ref:`default constructor <lec6_basis_con_de>`
so that we can control the default behaviors of ``_real`` and ``_imag`` when
users create default complex numbers.

.. code-block:: cpp
    :linenos:
    :emphasize-lines: 3-6

    class ComplexNumber {
    public:
        ComplexNumber() {
            _real = 0.0;
            _imag = 0.0;
        }
    private:
        double _real, _imag; // real and imaginary parts
    };

We want to customize a constructor so that it can take input doubles. In
addition, we want to make the imaginary has default value 0. In addition, we
want to implement a helper function for printing the values.

.. code-block:: cpp
    :linenos:
    :emphasize-lines: 4-13

    class ComplexNumber {
    public:
        ...
        // constructor with two doubles, note that we don't
        // mark explicit, so that double can be converted to ComplexNumber
        ComplexNumber(double real, double imag = 0.0) {
            _real = real;
            _imag = imag;
        }
        // implement a helper function for printing
        void print() const {
            std::cout << "real=" << _real << ", imag=" << _imag << '\n';
        }
    private:
        double _real, _imag; // real and imaginary parts
    };

.. note::

    The constructor above an be used to implicitly convert a ``double`` into
    a ``ComplexNumber`` by assigning the ``double`` as the real part and make
    the imaginary component zero.

Now, let's think about some member functions. We want to provide the following
functionalities for ``ComplexNumber``:

1. setting/getting real & imaginary parts,
2. copying other ``ComplexNumber`` numbers,
3. making a copy of "myself", i.e. ``this``,
4. computing the conjugate/modulus, and
5. adding/subtracting complex numbers.

Set/Get Values
``````````````

Of course, we can do the traditional set/get for bullet 1, like what we did
for ``MyClass``, but a neat way is to utilize
:ref:`function overloading <lec4_func_adv_ov>`.

.. code-block:: cpp
    :linenos:
    :emphasize-lines: 4-11

    class ComplexNumber {
    public:
        ...
        // real returns the normal reference to _real
        double &real() { return _real; }
        // this one is overloaded to return a copy of real
        double real() const { return _real; }

        // similarly for imag
        double &imag() { return _imag; }
        double imag() const { return _imag; }
    private:
        double _real, _imag; // real and imaginary parts
    };

Why ``real`` and ``imag`` are considered as function overloading? Well, let's
take a look at their generic interfaces:

.. code-block:: cpp

    double &ComplexNumber::real(ComplexNumber *this);
    double ComplexNumber::real(const ComplexNumber *this);
    double &ComplexNumber::imag(ComplexNumber *this);
    double ComplexNumber::imag(const ComplexNumber *this);

Since they are differ **not only in return type**, they are valid overloaded
functions.

**Question: what if we don't have constant qualifier in the second versions?**

With this interfaces, you can do:

.. code-block:: cpp

    ComplexNumber a(1.0, 1.0);
    // which real/imag are called?
    a.real() = 2.0;
    a.imag() = -1.0;
    // what about the following two?
    std::cout << "real=" << a.real();
    std::cout << "imag=" << a.imag();

.. note:: ``std::cout`` only accepts objects with constant qualifier.

Copy & Make Copies
``````````````````

Similarly, we utilize :ref:`function overloading <lec4_func_adv_ov>` for
implementing these two functionalities.

.. code-block:: cpp
    :linenos:
    :emphasize-lines: 4-11

    class ComplexNumber {
    public:
        ...
        // make a copy
        // because we won't modify this, make it constant
        ComplexNumber copy() const {
            // what is the type of *this? and what constructor is called?
            ComplexNumber tmp(*this);
            return tmp;
            // or return *this; // do you get it?
        }
    private:
        double _real, _imag; // real and imaginary parts
    };

And copy other complex numbers:

.. code-block:: cpp
    :linenos:
    :emphasize-lines: 4-8

    class ComplexNumber {
    public:
        ...
        // copy other values, no constant qualifier
        void copy(const ComplexNumber &other) {
            _real = other._real;
            _imag = other._imag;
        }
    private:
        double _real, _imag; // real and imaginary parts
    };

Compute Conjugate and Modulus
`````````````````````````````

Given a complex number with *Euler form*, i.e. :math:`z=x+yi`, where :math:`i`
is the *imaginary unit*, i.e. :math:`i=\sqrt{-1}`. Then, the modulus of
:math:`z` is:

.. math::

    \left\vert z\right\vert&=\sqrt{x^2+y^2}

and the conjugate is:

.. math::

    \bar{z}&=x-yi

.. code-block:: cpp
    :linenos:
    :emphasize-lines: 4-11

    class ComplexNumber {
    public:
        ...
        // modulus, require <cmath>
        double modulus() const {
            return std::sqrt(_real*_real+_imag*_imag);
        }
        // conjugate
        ComplexNumber conj() const {
            return ComplexNumber(_real, -_imag);
        }
    private:
        double _real, _imag; // real and imaginary parts
    };

Add/Subtract ``ComplexNumber``
``````````````````````````````

Given complex numbers :math:`z_1` and :math:`z_2`, their addition and
subtraction are:

.. math::

    z_1+z_2&=\left(x_1+x_2\right)+\left(y_1+y_2\right)i

    z_1-z_2&=\left(x_1-x_2\right)+\left(y_1-y_2\right)i

.. code-block:: cpp
    :linenos:
    :emphasize-lines: 4-11

    class ComplexNumber {
    public:
        ...
        // add, i.e. this+rhs
        ComplexNumber add(const ComplexNumber &rhs) const {
            return ComplexNumber(_real+rhs.real(), _imag+rhs.imag());
        }
        // subtract, i.e. this-rhs
        ComplexNumber sub(const ComplexNumber &rhs) const {
            return ComplexNumber(_real-rhs.real(), _imag-rhs.imag());
        }
    private:
        double _real, _imag; // real and imaginary parts
    };

Usages:

.. code-block:: cpp

    ComplexNumber z1(1.0); // what is z1.imag()?
    ComplexNumber z2(2.0, -1.0);

    // tmp vars can call constant member functions

    // what is the value?
    z1.add(z2).print();

    // can we do this? answer: yes, but why?
    z1.add(3.0).print();

    z2.sub(z1).print(); // what about this?

Put Everything Together
```````````````````````

The overall implement can be found in :nblec_6:`complex` including some
usage codes.

In addition, the archive contains the header ``ComplexNumber.hpp``, the source
``ComplexNumber.cpp`` and a main program for testing. This is a good exercise
for understanding how to separate declarations and implementations with
classes.

The ``Array`` Class
+++++++++++++++++++

.. _lec6_class_adv:

Advanced Topics of ``class``
============================

.. contents::
   :local:
   :backlinks: top
