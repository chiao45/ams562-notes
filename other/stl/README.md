# Introduction to *Standard Template Library* (STL) #

**STL** contains four components:

## Containers ##

All containers share some common operations, such as ```pop```, ```insert```, ```push```, ```erase```, ```range-for-loop```, etc. The actual uses may vary. STL containers give us a standard yet powerful way to represent and manipulate our data. Two most important features of why we should use STL containers are: a) very reliable, i.e. people all over the world use them and keep testing them on different systems. b) portable, i.e. there is an obvious reason why they are tagged with **standard**! All vendor implementations (GNU, Microsoft, Clang, Intel, HP, etc) must stay with standard so that their implementation can be considered as ```standard```, i.e. ```namespace std```. So if you use STL containers for your data, your code will run on ```Windows```, ```Linux```, ```MacOS```, etc.

[Reference: cppreference](http://en.cppreference.com/w/cpp/container)

### Sequences containers (fundamental data structures) ###

- ```std::vector``` in ```<vector>```
  - dynamic array like container.
  - most efficient and widely used container.
  - insertion/deletion in the middle is expensive.
  - popping/pushing from back is efficient (if you do it right).
  - constant data accessing.
- ```std::list``` in ```<list>```
  - doubly linked list like container.
  - data accessing is slow.
  - efficient element insertion and deletion.
- ```std::deque``` in ```<deque>```
  - doubly ended queue like container.
  - basically, a ```std::vector``` but supports adding/removing elements from both front and end.
- ```std::forward_list``` in ```<forward_list>```
  - singly linked list like container.
  - you can only walk through the list in one direction.
  - slightly efficient memory usage compared to ```std::list```
- ```std::array``` in ```<array>``` (```C++11```)
  - static array like container.
  - does not support data adding and removing.
  - ideal for small data on stack manipulation.

### Container adapters ###

- ```std::queue``` in ```<queue>```, adapts a *First In First Out* (FIFO) structure.
- ```std::stack``` in ```<stack>```, adapts a *Last In First Out* (LIFO) structure.
- ```std::priority_queue``` in ```<queue>```, heap implementation.

### Associative containers ###

Sorted data structures for quick look-up O(log(N)) time complexity.

- `std::set` collection of **unique** keys.
- `std::map` collection of **unique** key-value pairs.
- `std::multiset` non unique version of `std::set`.
- `std::multimap` non unique version of `std::map`.

For python programmers, you can think ```std::set``` as ```set``` and ```std::map``` as ```dictionary``` in python with limited features.

## Iterators ##

**Iterators** are the objects that are closely related to the elements in containers. The concept of iterator is to provide a standard way for describing how to traverse elements in a container. STL puts iterators into five types:

-   ```InputIterator``` only guarantees read from the pointed-to element.
-   ```OutputIterator``` only guarantees write to the pointed-to element.
-   ```ForwardIterator``` also guarantees increment the iterator toward ```++``` direction, e.g. ```std::forward_list::iterator```.
-   ```BidirectionalIterator``` you can now do ```--``` direction, e.g. ```std::list::iterator```.
-   ```RandomAccessIterator``` can randomly access any position in constant time, e.g. ```std::vector::iterator```.

**Iteratos are very like pointers**, in fact they are just wrapped around pointers, i.e. the dereference operator ```*``` and access-field operator ```->``` are valid for iterators. However, there are several things you need to pay attention to.

-   For a ```RandomAccessIterator``` ```iter```, we can do ```iter+5``` to get to its 5-th position. However, this doesn't work for a ```BidirectionalIterator```, e.g. you cannot do ```+n``` on ```std::list::iterator```, why?
-   Similarly, for ```RandomAccessIterators``` ```iter1``` and ```iter2```, you can compire them by using ```<``` or ```>```, i.e. if the element that ```iter1``` points to lies left to (in memory) the one that ```iter2``` points to, then we say ```iter1 < iter2```. Similarly, this doesn't work for ```BidirectionalIterators```.
-   In general, when you work with iterators, always using ```==``` and ```!=```!
-   Secondly, in terms of moving the iteratos, if you are not sure what containers users will use, using the following **standard** operations to move iterators:
    -   ```std::advance```, advance an iterator for a certain value, e.g.

    ```c++
    std::advance(iter, 4); // iter will points to the 4-th element from the current one
    ```
    -   ```std::next```, return an iterator of next (n) element.

    ```c++
    auto iter1 = std::next(iter); // iter1 points to iter's next, iter unchange
    auto iter2 = std::next(iter, 2); // iter2 points to the second element from iter
    ```

    -   ```std::prev```, opposite of ```std::next```.
    -   ```std::distance```, get the **number of elements** between two iterators.


    ```c++
    int n = std::distance(iter1, iter2); // n is the number of element between iter1
                                    // and iter2, w/o iter2
    ```
-   However, the drawback is that you hide the time complexity.

Note that we will mainly deal with ```std::vector```, and the iterators of it are ```RandomAccessIterators``` and **equivalent** to pointers of a dynamic array. This means:
```c++
// For vector's iterators, iter, iter1, iter2
std::advance(iter, 4);                  iter+=4;
auto iter1 = std::next(iter);           auto iter1 = iter+1;
int n = std::distance(iter1, iter2);    int n = iter2-iter1;
```

## Algorithms ##

Based on standardizing how to traverse containers, STL also implements a collection of algorithms such as ```copy```, ```assign```, ```search```, ```for_each```, ```max/min```, ```partition```, ```sort```, ```binary search```, etc. Again, use these whenever possible to reduce your developing time and increase the portability and robustness of your code.

[Algorithm header](http://en.cppreference.com/w/cpp/algorithm)

### Functors/C++11 Lambdas ###

**Functors** or **function objects** are overloaded function call operator, i.e. ```operator()```.

```c++
class Less {
public:
    inline bool operator()(double a, double b) const {
        return a<b;
    }
};

int main() {
    Less less;
    if (less(1.0, 2.0))
        ...
    else
        ...
}
```

A powerful functionality of functors is that they can hold addtional information through ```constructors``` and can be used inside the function call body, i.e. ```operator()```.

```c++
#include <vector>
#include <algorithm>

class BetterThanAverage {
public:
    // capture the informatrion through constructor
    BatterThanAverage(double avg) :
        avg_(avg) {}

    inline bool operator()(double a) const {
        return a>avg_;
    }
private:
    double avg_;
};
int main() {
    BetterThanAverage bta(68.0);
    std::vector<double> student_scores(100);
    // do something with student_scores
    ...
    // using standard algorithm count_if
    // count_if require a unary boolean callable object
    int num_bta = std::count_if(student_scores.begin(),
        student_scores.end(), bta);
    // black-box right?
}
```

In general, in order to write the same code in C is not easy, you need an ugly ```struct``` that holds the information of average score.

C++11 lambda is C++ solution to **Lambda Calculus**. It's backend compatible to functors. Equiped with algorithm in C++, the solution that modern C++ gives for functional programming and black-box routines is elegant and powerful. We will talk about lambdas in the future lectures. Here I give an example of how to do the same thing with lambda.

```c++
#include <vector>
#include <algorithm>

int main() {
    double avg = 68.0;
    std::vector<double> student_scores(100);
    ...
    auto bta = [=](double x){return x>avg;};
    int num_bta = std::count_if(student_scores.begin(),
        student_scores.end(), bta);
}
```

Or you can even construct lambda in place:

```c++
#include <vector>
#include <algorithm>

int main() {
    double avg = 68.0;
    std::vector<double> student_scores(100);
    ...
    int num_bta = std::count_if(student_scores.begin(),
        student_scores.end(), [=](double x){return x>avg;});
}
```

## What we will focus ##

-   ```std::vector``` and ```RandomAccessIterators```
-   [algorithm](http://en.cppreference.com/w/cpp/algorithm)
-   [random](http://en.cppreference.com/w/cpp/header/random)
-   functors and C++11 lambdas
