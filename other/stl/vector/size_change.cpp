//
// Understand how size grows in vectors

#include <vector>
#include <iostream>
#include <string>

template<typename T>
inline void print_vec(const std::vector<T> &v) {
    for (const auto & i : v) std::cout << i << ' '; std::cout << '\n';
}

template<typename T>
inline void get_size_cap(const std::vector<T> &v) {
    std::cout << "size: " << v.size() << ", capacity: " << v.capacity() << '\n';
}

struct Book {
    Book() {
    }
    Book(const std::string &name_, const std::string &author_) :
        name(name_), author(author_) {
    }

    Book & operator=(const Book & other) {
        name = other.name;
        author = other.author;
        return *this;
    }
    //
    // Using public members
    std::string name = "N/A", author = "N/A";
};

//
// We need to overload ostream operator in order to output Book
// in print_vec
std::ostream & operator<<(std::ostream & out, const Book & book) {
    out << '[' << book.name << ',' << book.author << ']';
    return out;
}

int main() {
    //
    // Create a vector of Book, with size zero
    std::vector<Book> books;

    //
    // Assume we know that there are at most 4 books
    // need to be put in books
    //
    // reserve storage for 4 books
    books.reserve(4);

    get_size_cap(books);

    //
    // Now push_back books and check size/cap at the same time
    books.push_back(Book("book1", "author1"));
    std::cout << "push 1\n";
    get_size_cap(books);
    print_vec(books);

    books.push_back(Book("book2", "author2"));
    std::cout << "push 2\n";
    get_size_cap(books);
    print_vec(books);

    books.push_back(Book("book3", "author3"));
    std::cout << "push 3\n";
    get_size_cap(books);
    print_vec(books);

    books.push_back(Book("book4", "author4"));
    std::cout << "push 4\n";
    get_size_cap(books);
    print_vec(books);

    //
    // Now, we say the last book has been sold, so we pop
    // it from the stack
    books.pop_back();
    std::cout << "pop 4\n";
    get_size_cap(books);
    print_vec(books);

    //
    // Now, you boss told you that there will be another
    // 6 books ariving soon, so you may think 2 reserve
    // 6 more storage for books
    books.reserve(10);
    std::cout << "reserve more\n";
    get_size_cap(books);

    //
    // Now, assume you want to "assign" two books instead
    // of push them, so you first resize the stack to 5
    books.resize(5);
    std::cout << "resize to 5\n";
    get_size_cap(books);
    // REMARK! if the new size is not exceed the capacity
    // then resizing can be VERY efficient
    books[3] = Book("newbook1", "newauthor1");
    // however, we may not always know the size
    // so we can use back to access the last element!
    books.back() = Book("newbook2", "newauthor2");
    print_vec(books);

    //
    // Quickly fill in all slots
    for (int i = books.size(); i < books.capacity(); ++i)
        books.push_back(Book("newbook"+std::to_string(i-2),
          "newauthor"+std::to_string(i-2)));
    std::cout << "use all storage\n";
    get_size_cap(books);
    print_vec(books);

    //
    // Now, assume that after holiday, you sold all the books.
    // you then can use clear to clear all contents
    books.clear();
    std::cout << "after clear\n";
    get_size_cap(books);

    //
    // To finally free up all memory before ending the program
    // we can call shrint_to_fit
    books.shrink_to_fit();
    get_size_cap(books);
    // REMARK! std::vector::shrink_to_fit is introduced since c++11
    // and it will fit the capacity to the current size
    return 0;
}
