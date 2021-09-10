
#include <iostream>

int main() {

  double *data = nullptr;
  unsigned long HUGE = 2e3;
  data = new double[HUGE];

  delete[] data;
}
