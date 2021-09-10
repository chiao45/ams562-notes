
#include <iostream>

void print(int i) { std::cout << i << std::endl; }

int main() {

  double tol = 1e-6;
  double &tol_ref = tol;
  double *tol_ptr = &tol;

  tol_ref = 1e-2;
  std::cout << tol << std::endl;      // what is the output?
  std::cout << *tol_ptr << std::endl; // what about this?
  *tol_ptr = 0.0;
  std::cout << tol_ref << std::endl;
}
