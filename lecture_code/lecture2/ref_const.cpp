
#include <iostream>

void print(int i) { std::cout << i << std::endl; }

int main() {

  const double tol = 1e-2;

  double &tol_ref = tol; // error!

  char &A = 'A'; // error ! binding address to temporary char

  const double &c_tol_ref = tol;         // okay!
  const std::string &str_ref = "ams562"; // ok
}
