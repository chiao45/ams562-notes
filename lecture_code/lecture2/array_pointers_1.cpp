#include <iostream>

int main() {

  char name0[7] = {'A', 'd', 'r', 'i', 'a', 'n', 0};
  // be careful when creating arrays of chars
  // Without the null termination std::cout will run till it hits "\0"
  char name1[7] =
      "adrian"; // this initialization adds a null termination char at the end

  std::cout << "name " << name0 << std::endl;
  std::cout << "name " << name1 << std::endl;
}
