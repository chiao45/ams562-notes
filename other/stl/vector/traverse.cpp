//
// How to play with iterators in vector

#include <vector>
#include <iostream>

template<typename T>
inline void print_vec(const std::vector<T> &v) {
    // note that cbegin and cend are not necessary
    // since begin and end also have const version
    // but cbegin and cend are clear to read
    for (auto it = v.cbegin(); it != v.cend(); ++it)
        std::cout << *it << ' ';
    std::cout << '\n';
}

int main() {
    //
    // First let's create a vector of ints
    std::vector<int> v(10);

    //
    // v is size of 10

    //
    // loop through it using iterator
    //
    // We can see this is just a for loop
    // with init iterator at v's beginning
    // and endding before v's end, which is
    // the position right pass the last of v
    //
    // As I mentioned in class, iterators are
    // just pointers for vector
    // and const_iterators are just const pointers
    // for vector
    for (std::vector<int>::iterator iter = v.begin();
      iter != v.end(); ++iter)
        *iter = 1;

    std::cout << "v is: ";
    print_vec(v);

    //
    // The above example is fine, the way to initialize
    // the iterator is too ugly, we can use auto
    for (auto it = v.begin(); it != v.end(); ++it)
        *it = 2;

    std::cout << "v is: ";
    print_vec(v);

    // we can of course use the old old tradition
    for (int i = 0; i < v.size(); ++i)
        v[i] = i+1;

    std::cout << "v is: ";
    print_vec(v);

    //
    // Finally, the range for loop for containers
    // syntax is
    //      for (typename element : container)
    //              do something with element
    // usually we use auto with reference
    for (auto & i : v)
        i = 0;
    std::cout << "v is: ";
    for (const auto & i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}
