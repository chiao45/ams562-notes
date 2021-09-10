
#include <iostream>

void print(int i) { std::cout << i << std::endl; }

int main() {

  int a = 2;
  int a_copy = a;
  int &b = a;

  print(a);
  print(a_copy);
  print(b);
  std::cout << "initial values above" << std::endl;

  a = 3;
  print(a_copy);
  print(b);
  std::cout << "first change" << std::endl;

  b = 100;
  print(a);
  print(a_copy);
  std::cout << "second change" << std::endl;
}
