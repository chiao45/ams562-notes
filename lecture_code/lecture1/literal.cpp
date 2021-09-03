#include <iostream>
#include <string>

void print_message(int a) { std::cout << "int " << a << ::std::endl; }
void print_message(long int a) { std::cout << "long int " << a << ::std::endl; }
void print_message(unsigned long int a) {
  std::cout << "unsigned long  int " << a << ::std::endl;
}
void print_message(unsigned int a) {
  std::cout << "unsigned  int " << a << ::std::endl;
}
void print_message(float a) { std::cout << "float " << a << ::std::endl; }
void print_message(double a) { std::cout << "double " << a << ::std::endl; }
void print_message(std::string a) {
  std::cout << "string " << a << ::std::endl;
}

int main() {
  print_message(-32);
  print_message(-32u);
  print_message(32ul);
  print_message(32l);
  print_message(32u);

  print_message(1.0f);
  print_message(-2.0);
  print_message(-5.21);

  print_message("\"A\"");
  print_message("\'");
  // literals
  // 32, 1, -2, -100, 30001,...
  // 32l // long literal
  return 0;
}
