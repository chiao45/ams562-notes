
#include <iostream>

void print(int i) { std::cout << i << std::endl; }

int main() {

  int a = 4;
  int *a_ptr = &a;

  std::cout << a_ptr << std::endl;
  std::cout << a << "==" << *a_ptr << '\n' << std::endl;

  *a_ptr = 2;

  std::cout << "a = " << a << std::endl;
}
