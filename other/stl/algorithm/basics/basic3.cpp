// In this example, we will learn how to find the max
// and minimum of a vector

#include <algorithm>
#include <cstdlib> // std::rand()
#include <iostream>
#include <vector>

#define N 10

int main() {

  //
  // toy
  std::vector<int> v(N);
  for (auto &i : v)
    i = std::rand() % 100;

  //
  // simple random vector
  for (auto it = v.begin(); it != v.end(); ++it)
    std::cout << *it << ' ';
  std::cout << '\n';

  //
  // find the maximum value
  auto itmax = std::max_element(v.begin(), v.end());

  std::cout << "the max value of v is: " << *itmax
            << ", it's of position: " << itmax - v.begin() << '\n';

  //
  // find the min
  auto itmin = std::min_element(v.begin(), v.end());
  std::cout << "the min value of v is: " << *itmin
            << ", it's of position: " << itmin - v.begin() << '\n';
  return 0;
}
