// This demo shows how to efficiently
// use vector
#include <vector>
#include <iostream>

template<typename T>
inline void print_vec(const std::vector<T> &v) {
    // this is the range for
    for (const auto & val : v)
        std::cout << val << ' ';
    std::cout << '\n';

    // content:container, content in container
    // usully use const auto & for constant
    // and auto & for non constant
}

int main() {

    using std::vector;
    using std::cout;

//     // construct a vector of int's
//     vector<int> v1(3);

//     // three element spaces
//     // using iterator to assign values
//     for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); ++iter)
//         *iter = 1;
//     // This is ugly right, you can either
//     // using my_iterator = vector<int>::iterator;
//     // or
//     for (auto iter = v1.begin(); iter != v1.end(); ++iter)
//         *iter = 1;

//     cout << "The size of v1 is " << v1.size() << '\n'
//          << "The capacity of v1 is " << v1.capacity() << '\n'
//          << "The pointer's address is " << v1.data() << '\n'
//          << "The contents are: \n";
//     print_vec(v1);

//     // add an element that require reallocation
//     v1.push_back(3);
//     cout << '\n';

//     // once it's reach its max capacity, c++ will allocate another
//     // array with 20% more storage

//     cout << "The size of v1 is " << v1.size() << '\n'
//          << "The capacity of v1 is " << v1.capacity() << '\n'
//          << "The pointer's address is " << v1.data() << '\n'
//          << "The contents are: \n";
//     print_vec(v1);

//     // change the last element
//     v1.back() = 10;
//     cout << '\n';

//     cout << "After changing the last element, v1 is \n";
//     print_vec(v1);

//     // erase the third element
//     v1.erase(v1.begin()+2);
//     cout << "After erasing the third element, v1 is \n";
//     print_vec(v1);
//     cout << '\n';
//     cout << "The size of v1 is " << v1.size() << '\n'
//          << "The capacity of v1 is " << v1.capacity() << '\n'
//          << "The pointer's address is " << v1.data() << '\n'
//          << "The contents are: \n";

    cout << "Now, let's see how to incrementally construct a vector\n\n";

    vector<double> v2;

    cout << "Empty vector v2, size is: " << v2.size() << '\n'
         << "The capacity of v2 is: " << v2.size() << '\n';

    // now we reserve space
    v2.reserve(5);

    cout << "After reserve, the capa is: " << v2.capacity() << '\n';

    // I will incrementally add elements, see carefully about
    // the following loop
    for (int i = 0; i < 6; ++i) {
        cout << '\n'
             << "Before pushing back:\n"
             << "size of v2 is " << v2.size() << '\n'
             << "Capacity is: " << v2.capacity() << '\n'
             << "The memory addree is: " << v2.data() << '\n'
             << "The size given by subtraction last iterator and first iterator is: "
             << v2.end()-v2.begin() << '\n';

        v2.push_back(static_cast<double>(i));

        cout << "\nAfter pushing back:\n"
             << "size of v2 is " << v2.size() << '\n'
             << "Capacity is: " << v2.capacity() << '\n'
             << "The memory addree is: " << v2.data() << '\n'
             << "The size given by subtraction last iterator and first iterator is: "
             << v2.end()-v2.begin() << "\n\n";
    }

    // See there is no memory allocation whatsoever.
    // For project2, the polygon should be constructed in this way!
}
