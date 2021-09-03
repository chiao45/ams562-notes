#include <iostream>

double mul2(double x) { return x * 2; }
void printxmul2(double x) {
  std::cout << "2 * " << x << " is " << mul2(x) << "\n";
}

int main() {
  printxmul2(2.234);

  return 0;
}
