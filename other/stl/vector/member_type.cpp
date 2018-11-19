// Member types

struct Type {
    typedef double my_type;
    // or
    using my_int = int;
};

// for template
template<typename T>
struct Class {
    using my_type = T;
};

// note that member types are also sensitive to
// private and public

int main() {
    // create a double
    double a;
    Type::my_type b;
    Class<double>::my_type c;

    // create an int
    int i;
    Type::my_int j;
    Class<int>::my_type k;
}
