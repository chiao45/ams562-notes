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

Having a Valid ``T`` Type
-------------------------

In most

Using Vector Efficiently
------------------------
