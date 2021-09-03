
#include <iostream>

void swap(int &, int &);

int main(void) {
  int a = 2;
  int b = 4;
  int temp;
  std::cout << temp;
  std::cout << "a = " << a << " b = " << b << std::endl;

  swap(a, b);

  std::cout << "a = " << a << " b = " << b << std::endl;
}

void swap(int &a, int &b) {
  int temp = b;
  b = a;
  a = temp;
}
