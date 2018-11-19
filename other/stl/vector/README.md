## Using `std::vector` ##

```std::vector``` is the most widely used container in STL. The reason is simple: because arrays can always give you better performance due to the contiguous memory. ```std::vector``` is different from the ```Vector``` we learned in computational linear algebra section. ```std::vector```, or more precisely speaking, dynamical array, is the simplest yet most widely used **data structure**.

Please use the reference: [http://en.cppreference.com/w/cpp/container/vector](http://en.cppreference.com/w/cpp/container/vector)

Template arguments (traditional version):
```c++
namespace std {
template<class T, class Allocator = std::allocator<T> >
vector;
}
```

The first argument is they type we want ```std::vector``` hold for us. ```Allocator``` is the memory management tool, which by default uses ```std::allocator``` (the standard allocator for all ```std```). **90% time people don't worry about this, for this class, we will just deal with ```class T```.**

```c++
using my_vector = std::vector<double>;

// simple but not recommend
using my_matrix = std::vector<std::vector<double> >;

struct Point2D {int x, y;};
using PointCloud = std::vector<Point2D>;

#include <complex>
using my_cplx_vector = std::vector<std::complex<double> >;
```

### Important member types

Given a type ```T```, there are several important **member types** for ```std::vector<T>```:

-   ```std::vector<T>::value_type```: ```T```
-   ```std::vector<T>::size_type```: ```std::size_t```, (for 32-bit computers it's 32 bit **unsigned** integer, 64 bit unsigned integer for 64-bit computers).
-   ```std::vector<T>::difference_type```: ```std::ptrdiff_t```, (for 32-bit computers it's 32 bit **signed** integer, 64 bit signed integer for 64-bit computers, it stands for **p**oin**t**e**r** **diff**erent **t**ype).
-   ```std::vector<T>::reference```: ```T&```.
-   ```std::vector<T>::const_reference```: ```const T&```.
-   ```std::vector<T>::pointer```: ```T*```.
-   ```std::vector<T>::const_pointer```: ```const T*```.
-   ```std::vector<T>::iterator```: ```RandomAccessIterator``` on ```T```.
-   ```std::vector<T>::const_iterator```: Constant ```RandomAccessIterator``` on ```T```.

For more on member types, see ```member_type.cpp```.

### Constructors

Here are some commonly used constructors:

-   ```vector()```: Default construction.
-   ```vector(size_type n)```: Create a vector of size n.
-   ```vector(size_type n, const T &value)```: Create a vector of size n with initial value ```value```.
-   ```vector(const vector &other)```: Copy constructor.
-   ```template<class InputIterator> vector(InputIterator first, InputIterator last)```: Copy values from first to last, note you can also use raw points!

### Member functions

-   ```assign```: assign values.
-   ```front```: get the first element (```reference``` and ```const_reference```).
-   ```back```: get the last element (```reference``` and ```const_reference```).
-   ```data```: get the raw data (pointer).
-   ```begin```: return an iterator to the beginning.
-   ```cbegin```: return an constant iterator to the beginning.
-   ```end```: return an iterator to the end (one right after the last element).
-   ```cend```: return an constant iterator to the end.
-   ```size```: reutrn the current size.
-   ```max_size```: maximum possible size, i.e. maximum value of ```size_type```.
-   ```empty```: check if the container is empty.
-   ```reserve```: reserves storage.
-   ```capacity```: returns the number of elements that can be held in currently allocated storage.
-   ```clear```: clear contents.
-   ```insert```: inserts element to a certain position or range of positions.
-   ```erase```: erase an element or certain range of elements.
-   ```push_back```: adds an element to the back.
-   ```pop_back```: removes the last element.
-   ```resize```: change the current size.
-   ```swap```: swap the contents (only swap the pointer, very efficient).
-   ```operator[]```: access memebrs (```reference``` and ```const_reference```).
-   ```operator=```: assign to another vector.

For project 2, you need to understand ```front```, ```back```, ```begin```, ```end```, ```size```, ```capacity```, ```push_back```, ```pop_back```, and ```operator[]```.

### How to use ```std::vector``` efficiently

We know that internal content of ```std::vector``` is a dynamic array. Dynamic memory allocation is one of the top killers of performance. Before we dig into more detail, we need to understand how ```std::vector``` increment.

```size``` is the current size which can be accessed by using ```operator[]``` or iterators, it is the size between ```begin``` and ```end```.

```capacity``` is the available storage before resizing. It's determined by ```reserve```.

Try to avoid inserting and erasing elements in the middle.

Good practices for using ```std::vector``` are:

-   If you know the size of your data, construct a vector with certain size.
-   If you are not sure about the size, then reserve capacity for the approximation of max storage and then construct the vector inrementally, i.e. using ```push_back```.
-   Try to avoid insert/erase elements in the middle.
-   If you have to resize/reserve, do not call it inside loops.
-   Always always allocate more storage than you actually need!

For detail, see ```eff_vec.cpp```
