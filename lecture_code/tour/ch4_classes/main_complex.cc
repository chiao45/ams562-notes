#include "complex.h"

void f(complex z) {
  complex a{2.3};
  complex b{1 / a};
  complex c{a + z * complex{1, 2.3}};
  if (c != b) {
    c = -(b / a) + 2 * b;
  }
}

int main() {

  const complex c1;

  complex c2{2, 4};

  c2 = c1; // okay
           // c1 = c2; // not okay operator= is not-const member function
  double d1 = c1.real();     // const member
  double d_imag = c1.imag(); // const member
}
