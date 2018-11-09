// this is a demo for understanding
// differences with overloading operators
// as free vs as member functions
// In this example, operators - are overloaded
// as member functions and operators + are
// overloaded free functions

#include <iostream>

class Obj {
 public:
  // keep in mind the syntax
  Obj operator-() const { return *this; }
  Obj operator-(const Obj&) const { return *this; }
};
// as free functions
Obj operator+(const Obj& a) { return a; }
Obj operator+(const Obj& l, const Obj& r) { return l; }

int main() {
  Obj a;
  -a;     // calls a's -
  a - a;  // calls a's - (binary)
  // for better understanding
  a.operator-();
  a.operator-(a);

  +a;     // calls free +
  a + a;  // calls free + (binary)
  // for better understanding
  operator+(a);
  operator+(a, a);

  return 0x0;
}
