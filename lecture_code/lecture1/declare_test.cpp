
#include <iostream>

int main(void) {
  int temp;
  std::cout << temp << std::endl; // undefined behaviour
  temp = 5;
  std::cout << temp << std::endl;
}
