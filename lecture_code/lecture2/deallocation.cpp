
#include <iostream>

int main() {

  int *ptr_main = nullptr;

  {
    int *ptr = new int; // points to int allocated on the heap
    ptr_main = ptr;
  } // *ptr out of scope and destroyed

  // create new pointer and intialize to value 3
  std::cout << *ptr_main << std::endl;
  delete ptr_main;
}
