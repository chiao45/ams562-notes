// In this example, we show how to replace
// a certain amount of elements in a vector
// also fill in a certain range with some
// constant value

#include <algorithm>
#include <iostream>
#include <vector>

#define N 10

int main(int argc, char *argv[]) {

  //
  // create our toy
  std::vector<int> v(N);

  for (int i = 0; i < N; ++i)
    v[i] = 2 * i + 1;

  //
  // printing
  std::cout << "initially, v is: ";
  for (const auto &i : v)
    std::cout << i << ' ';
  std::cout << '\n';

  //
  // replace 5 by 100
  // replace(begin, end, old, new)
  std::replace(v.begin(), v.end(), 5, 100);

  std::cout << "after replacing value 5 by 100, v is:\n";
  for (const auto &i : v)
    std::cout << i << ' ';
  std::cout << '\n';

  //
  // Now, we say let's fill in first 5 elements with 1

  std::fill(v.begin(), v.begin() + 5, 1);

  std::cout << "after filling in first 5 elements in v by 1, v is:\n";
  for (const auto &i : v)
    std::cout << i << ' ';
  std::cout << '\n';

  //
  // Fill rest 5 by 2 using fill_n
  std::fill_n(v.begin() + 5, 5, 2);

  std::cout << "after filling the rest by 2, v is:\n";
  for (const auto &i : v)
    std::cout << i << ' ';
  std::cout << '\n';

  return 0;
}
