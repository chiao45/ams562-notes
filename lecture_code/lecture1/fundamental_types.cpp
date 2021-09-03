
#include <iostream>

int main(void) {
  bool b;       // Boolean, true/false
  char c;       // character 'a','z','9'
  int i;        // integer, -265, 32, 29
  double d;     // double-precision floating point number
  long l;       // double-precision floating point number
  double *ptr;  // pointer to double (address to variable)
  unsigned ui;  // non-negative integer, for example 0,1,999

  unsigned short fu = 0b1111111111111111;
  short fi = 0b0111111111111111;

  std::cout << "size of bool = " << sizeof(b) << " byte" << std::endl;
  std::cout << "size of char = " << sizeof(c) << " byte" << std::endl;
  std::cout << "size of double = " << sizeof(d) << " byte" << std::endl;
  std::cout << "size of int = " << sizeof(i) << " byte" << std::endl;
  std::cout << "size of long = " << sizeof(l) << " byte" << std::endl;
  std::cout << "size of pointer = " << sizeof(ptr) << " byte" << std::endl;
  std::cout << "size of ui = " << sizeof(ui) << " byte" << std::endl;

  std::cout << "max int = " << fi << std::endl;
  std::cout << "max unsigned = " << fu << std::endl;
}
