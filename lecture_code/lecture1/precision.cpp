#include <iostream>

int main() {
  float single_lhs = 1.1;
  float single_rhs = 1.10000004;
  std::cout << (single_lhs == single_rhs) << std::endl;
  // try the same with double
  double double_lhs = 1.1;
  double double_rhs = 1.10000004;
  std::cout << (double_lhs == double_rhs) << std::endl;
  return 0;
}
