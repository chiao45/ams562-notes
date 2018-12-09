#include <cblas.h>
#include <vector>
#include <iostream>

int main() {

  std::vector<double> x(10), y(10);
  for (int i = 0; i < 10; ++i)
    x[i] = i + 1;

  // copy x to y, then y = [1, 2, ... 10]
  cblas_dcopy(10, x.data(), 1, y.data(), 1);

  for (int i = 0; i < 10; ++i)
     std::cout << y[i] << ' ';
  std::cout << '\n';

  // axpy y = 2*x+y
  cblas_daxpy(10, 2.0, x.data(), 1, y.data(), 1);

  // nrm2 ||y||_2 = sqrt(sum(y_i^2))
  double nrm2 = cblas_dnrm2(10, y.data(), 1);
}
