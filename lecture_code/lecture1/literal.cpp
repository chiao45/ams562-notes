#include <iostream>
#include <string>
// This code depends on function overloading
// Function overloading is defining multiple functions with the same name
// Each function has the same name but differ in their input parameters
// You

void print_var(int a) { std::cout << "int " << a << ::std::endl; }
void print_var(long int a) { std::cout << "long int " << a << ::std::endl; }
void print_var(unsigned long int a) {
  std::cout << "unsigned long  int " << a << ::std::endl;
}
void print_var(unsigned int a) {
  std::cout << "unsigned  int " << a << ::std::endl;
}
void print_var(float a) { std::cout << "float " << a << ::std::endl; }
void print_var(double a) { std::cout << "double " << a << ::std::endl; }
void print_var(std::string a) { std::cout << "string " << a << ::std::endl; }
void print_var(char a) { std::cout << "char " << a << ::std::endl; }

int main() {
  // integer literals
  print_var(0b00001);  // binary integer literal
  print_var(0b01011);
  print_var(0xFFFFFu);
  print_var(0xFFFF);
  print_var(0b00001);  // binary
  print_var(0x0BF0);   // hexadecimal
  print_var(-32);
  print_var(-32u);
  print_var(32ul);
  print_var(32l);
  print_var(32u);
  // floating point literals
  print_var(1.0f);
  print_var(3.2e-1f);
  // doubles
  print_var(3.2e2);
  print_var(-2.0);
  print_var(-5.21);
  // String Literlas
  print_var("\"A\"");
  print_var("\'");
  print_var("\tHello World!\n");
  print_var("\Hello\v World!\n");
  // Char literals
  print_var('a');
  // literals
  // 32, 1, -2, -100, 30001,...
  // 32l // long literal
  return 0;
}
