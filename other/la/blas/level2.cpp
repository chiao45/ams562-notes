#include <cblas.h>
#include <vector>

int main() {
  // call mv to compute the matrix vector
  std::vector<double> M = {1, 2,  3,  4,  5,  6,  7,  8,
                           9, 10, 11, 12, 13, 14, 15, 16};
  // 4 x 4
  std::vector<double> v = {1, 2, 3, 4};

  std::vector<double> y(4);

  // y = 1.0*M*v
  cblas_dgemv(CblasRowMajor, CblasNoTrans, 4, 4, 1.0, M.data(), 4, v.data(), 1,
              0.0, y.data(), 1);

  // y = 1.0*v*M
  cblas_dgemv(CblasRowMajor, CblasTrans, 4, 4, 1.0, M.data(), 4, v.data(), 1,
              0.0, y.data(), 1);

  // notice that v*M is just tran(M)*v
}
