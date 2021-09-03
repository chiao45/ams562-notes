#include <iostream>

// Vector object is a "handle" containing pointer to elements
// and number of elements
// The number of elements can vary from Vector object to Vector object
// However, a single vector object always has the same size.
class Vector {
public:
  Vector(int s) : elem{new double[s]}, sz{s} {} // construct a Vector
  double &operator[](int i) { return elem[i]; }
  int size() { return sz; }

private:
  double *elem; // pointer to elements
  int sz;       // the nubmer of elements
};
// the members elem and sz are only accessible through
// the interface provided
// Vector(), operator[](), and size()

double read_and_sum(int s)
// read s integers from cin and return their sum;
// s is assumed to be positive
{
  Vector v(s); // Vector with s elements
  for (int i = 0; i != v.size(); ++i) {
    std::cin >> v[i]; // write to v[i] through [] operator which returns
                      // reference to elem[i]
  }
  double sum = 0;
  for (int i = 0; i != v.size(); ++i) {
    sum += v[i]; // sum read through [] operator
  }
  return sum;
}

int main() {
  //
  //
  int s = 3;
  read_and_sum(s);

  return 0;
}
