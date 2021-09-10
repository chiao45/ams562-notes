#include "Vector.h"
void fct(int n) {
  Vector v(n);
  // ... use v...
  {
    Vector v2(2 * n);
    v2.print();
    std::cout << "size of v2 " << sizeof(v2) << std::endl;
    v2.push_back(2);
    v2.print();
    std::cout << "size of v2 " << sizeof(v2) << std::endl;
  }
}

int main() {
  //
  fct(3);

  return 0;
}
