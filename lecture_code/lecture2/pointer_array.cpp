#include <iostream>

int main() {

  int *p1 = new int;
  delete[] p1; // wrong

  double *p2 = new double[2];
  delete p2; // Wrong
}
