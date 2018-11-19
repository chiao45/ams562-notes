// In this example, we show how to copy
// two vectors using std::copy

#include <algorithm>
#include <iostream>
#include <vector>

// size of vector
#define N 20

int main() {
  //
  // Construct two vectors
  std::vector<int> v1(N), v2(N);

  //
  // Assign values to v1
  for (int i = 0; i < N; ++i)
    v1[i] = i + 1;

  //
  // Copy the whole v1 to v2
  // copy(in_begin, in_end, out_begin)
  std::copy(v1.begin(), v1.end(), v2.begin());

  std::cout << "v1 is: ";
  for (const auto &i : v1)
    std::cout << i << ' ';
  std::cout << '\n';
  std::cout << "v2 is: ";
  for (const auto &i : v2)
    std::cout << i << ' ';
  std::cout << '\n';

  //
  // resize v2 to 5
  v2.resize(5);

  //
  // only copy 2nd to 6th element in v1 to v2
  std::copy(v1.begin() + 1, v1.begin() + 6, v2.begin());

  std::cout << "resize v2 to size 5, and only copy 2nd to 6th elements in v1"
            << " to v2, the results are:\n";
  for (const auto &i : v2)
    std::cout << i << ' ';
  std::cout << '\n';

  //
  // Alternatively, if you don't prefer precompute the iterators
  // you can use copy_n
  std::copy_n(v1.begin() + 6, 5, v2.begin());

  std::cout << "using copy_n, copy the 7th to 11th elements in v1"
            << " to v2, the results are:\n";
  for (const auto &i : v2)
    std::cout << i << ' ';
  std::cout << '\n';

  return 0;
}
