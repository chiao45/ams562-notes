
#include <iostream>

int main() {

  int *bad_ptr = 3;   // doesn't make sense  we have no memomory
  int *ptr = new int; // points to int allocated on the heap

  *ptr = 3;

  int *ptr_init = new int{3};
  // create new pointer and intialize to value 3
  std::cout << *ptr_init << std::endl;
}
