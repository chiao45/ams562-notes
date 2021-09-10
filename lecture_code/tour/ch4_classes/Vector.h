
#include <iostream>

class Vector {

public:
  // allocates mem on free store
  Vector(int s)
      : elem{new double[s]}, sz{s} // constructor: acquire resources
  {
    std::cout << " allocating " << sizeof(int) * s << " bytes of mem"
              << std::endl;
    for (int i = 0; i != s; ++i)
      elem[i] = 0;
  }

  // destructor free mem
  ~Vector() {
    std::cout << "free up mem " << sizeof(int) * sz << std::endl;
    delete[] elem;
  }
  // Intializing Containers
  // method 1 initializer-list constructor
  Vector(std::initializer_list<double> l)
      : elem{new double[l.size()]}, sz{static_cast<int>(l.size())} {
    std::copy(l.begin(), l.end(), elem);
  }

  // init with list of doubles
  // the question is do resize and copy
  // inefficient
  // solution: set up capacity
  // if sz> capcity double
  void push_back(double d) {
    // create new pointer to doubles
    double *new_elem;
    // allocate sz+1 doubles in heap
    new_elem = new double[sz + 1];
    // copy current doubles into mem
    for (int i = 0; i != sz; ++i) {
      new_elem[i] = elem[i];
    }
    new_elem[sz] = d;
    // free mem elem is pointing to
    delete[] elem;
    // point to new mem
    elem = new_elem;
    // add one to sz
    sz += 1;
  }; // add element at end increase size by one
  void print() {

    std::cout << "v: ";
    for (int i = 0; i != sz; ++i) {
      std::cout << elem[i] << " ";
    }
    std::cout << std::endl;
  }

  double &operator[](int i) { return elem[i]; }
  int size() const { return sz; };

private:
  double *elem;
  int sz;
};
