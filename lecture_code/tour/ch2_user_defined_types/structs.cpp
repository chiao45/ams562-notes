#include <iostream>

struct Vector {
  int sz;       // number of elements
  double *elem; // pointer to elements
};

// we pass v by non const reference
void vector_init(Vector &v, int s) {
  v.elem = new double[s]; // allocate an array of s doubles
  v.sz = s;
}
// new operator allocates memory from area called the
// free store
// dynamic memory
// heap
// Objects that live in the free store
// are independent of the scope in which
// they are created.
// The "live" until they are destroyed using the delete
// operator
//
double read_and_sum(int s)
// read s integers from cin and return their sum;
// s is assumed to be positive
{
  Vector v;
  vector_init(v, s);

  for (int i = 0; i != s; ++i) {
    std::cin >> v.elem[i];
  }
  double sum = 0;
  for (int i = 0; i != s; ++i) {
    sum += v.elem[i];
  }
  return sum;
}

// we asume that v is valid (aka) initialized with a value for members
void f(Vector v, Vector &rv, Vector *pv) {
  int i1 = v.sz;   // access through name
  int i2 = rv.sz;  // access through reference
  int i3 = pv->sz; // access through pointer
  std::cout << "Here are the sizes " << i1 << "  " << i2 << " " << i3
            << std::endl;
}
// We use .(dot) to access struct members through name (and through reference)
// -> to access struct members through a pointer.

int main() {
  //
  if (true) {

    int sz = 5;
    Vector v;
    vector_init(v, sz);

    Vector *pv = &v;
    Vector &rv = v;
    f(v, rv, pv);
  } else {

    double s = read_and_sum(3);

    std::cout << "sum of 3 numbers " << std::endl;
  }

  return 0;
}
