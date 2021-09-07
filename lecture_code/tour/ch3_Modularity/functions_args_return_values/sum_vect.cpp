
#include <iostream>
#include <vector>

int sum(const std::vector<int> &v) {
  int s = 0;

  for (const int i : v)
    s += i;

  return s;
}

void test(std::vector<int> v, std::vector<int> &rv) {
  v[1] = 99;  // modify v (a local variable)
  rv[2] = 66; // modify whaever rv refers to
}

int main() {
  std::vector<int> fib = {1, 2, 3, 5, 8, 13, 21};
  test(fib, fib);

  std::cout << fib[1] << ' ' << fib[2] << '\n';

  int x = sum(fib);

  std::cout << x << "\n";
}
