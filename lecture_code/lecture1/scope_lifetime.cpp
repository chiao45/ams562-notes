#include <complex>
#include <iostream>
#include <string>
#include <vector>

// scope and life time
int hello = 2;  // global namespace

double square(double a) {
  std::cout << "global hello in square function " << hello << std::endl;
  return a * a;
}

int main() {
  double local_main = 32;

  {
    std::cout << local_main << std::endl;
    double local_scope_d = 23;
    std::cout << local_scope_d << std::endl;
  }  // local _scope_d gets destroyed here
  // std::cout << local_scope_d << std::endl;

  std::cout << "global hello in main function" << hello
            << std::endl;  // print global scope hello
  double s3 = square(3);

  return 0;
}
