
#include <iostream>

int main() {
  int a;
  int b;
  int *p = &a;     // p holds a's addr
  int *&p_ref = p; // a reference of pointer
  p_ref = &b;      // what is p now?

  // similarly, since p is object, we can create pointers
  // that point to it
  int **pp = &p;            // pp holds p's address
  std::cout << *pp << '\n'; // what is the deref of pp
  *pp = &a;
  // what is p_ref now?
}
