#include <cblas.h>
#include <vector>

int main() {
  // compute C = 2.0*A*tran(A)
  // where A is 3 x 2, so C is 3 x 3
  std::vector<double> C(9);
  std::vector<double> A = {1, 2, 3, 4, 5, 6};
  //      [1, 2]
  //  A = [3, 4]
  //      [5, 6]

  // 'A', which is A is no transpose
  // 'B', which is tran(A) is transpose
  // so M = row of 'A' is 3
  //    N = col of 'B' is 3
  //    K = 2
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasTrans, 3, 3, 2, 2.0, A.data(),
              2, A.data(), 2, 0.0, C.data(), 3);
}
