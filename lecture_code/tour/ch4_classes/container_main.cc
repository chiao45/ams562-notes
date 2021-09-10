#include "Container.h"
#include <iostream>

void use(Container &c) {

  const int sz = c.size();
  for (int i = 0; i != sz; ++i) {
    std::cout << c[i] << "\n";
  }
}
void g() {
  Vector_container vc(10);
  for (int i = 0; i != vc.size(); ++i) {

    vc[i] = i;
  }
  use(vc);
}

void h() {
  List_container lc = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  use(lc);
}
// use functino uses c.size()
// operator[]
// Without knowing the implementation details
//
// A class that provides interface to a varitey of classes is polymorphic type

int main() {

  g();
  h();

  // Container c; abstract class
}
