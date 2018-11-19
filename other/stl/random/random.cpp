#include <ctime>
#include <iostream>
#include <random>
#include <vector>

int main() {
  // using time to generate a seed
  // note that seed is unsigned int
  auto seed = std::time(0);

  // now generate an engine
  std::mt19937 eng;
  eng.seed(seed);

  // given a uniform distribution from 0 to 1
  std::uniform_real_distribution<float> u(0.0f, 1.0f);

  // construct a uniform distributed vector of floats
  std::vector<float> v(20);

  for (auto first = v.begin(); first != v.end(); ++first)
    *first = u(eng);

  for (const auto &val : v)
    std::cout << val << ' ';
  std::cout << '\n';
  return 0;
}
