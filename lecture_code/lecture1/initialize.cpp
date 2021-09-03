#include <complex>
#include <iostream>
#include <string>
#include <vector>

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
void print_var(char a) { std::cout << "char " << a << std::endl; }
void print_var(bool a) { std::cout << "bool " << a << std::endl; }
void print_var(std::complex<double> a) {
  std::cout << "complex " << a.real() << " " << a.imag() << std::endl;
}

int main() {
  double d1 = 2.3;    // initialize d1 to 2.3
  double d2{2.3};     // initialize d2 to 2.3
  double d3 = {2.3};  // is optional with {}

  std::complex<double> z = 1;  // a complex number with double-precision
  std::complex<double> z2{d1, d2};
  std::complex<double> z3 = {d1, d2};
  print_var(z);
  print_var(z2);
  print_var(z3);

  std::vector<int> v{1, 2, 3, 4, 5, 6};  // vector of ints

  int i1 = 7.8;  // i1 becomes 7
  // int i2{7.8};   // error: narrowing conversion of double to int
  // = allows narrowing conversion
  // {} does not
  unsigned int wha = -1;  // What is the value?
  int whaaaa{wha};
  print_var(wha);
  print_var(whaaaa);

  auto b = true;     // a bool
  auto ch = 'x';     // a char
  auto i = 124;      // a int
  auto d = 1.2;      // a double
  auto z = sqrt(y);  // the type retured
  auto bb{true};     // a bool

  return 0;
}
