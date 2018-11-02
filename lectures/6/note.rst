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
you look at the :nblec_3:`constr-destr`.

More on Constructors
++++++++++++++++++++

Defining Member Functions
+++++++++++++++++++++++++

.. _lec6_class_adv:

Advanced Topics of ``class``
============================

.. contents::
   :local:
   :backlinks: top
