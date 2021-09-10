
#include <iostream>

int main() {
  const int a = 1;
  const int *p2c = &a;
  *p2c = 2;      // ERROR! a is constant
  p2c = nullptr; // fine
                 ///
  int b = 2;
  int *const p = &b; // you must initialize p
  *p = 1;            // fine
  p = nullptr;       // ERROR!

  const int *const cpc = &a; // const pointer to const int
                             // read declaration from right to left
}
