
#include <cmath>
#include <iostream>
#include <numeric> //iota
#include <stdexcept>

#include "Vector.h"

double sqrt_sum(Vector &v) {
  double sum = 0;
  for (int i = 0; i != v.size(); ++i) {
    sum += std::sqrt(v[i]);
  }
  return sum;
}

void f(Vector &v) {
  //...
  try { // exceptions here are handled by the handler defined below
    v[v.size()] = 7;
  } catch (std::out_of_range &err) {
    //... handle range error...
    std::cerr << err.what() << '\n';
  }
  //...
}

void test(Vector &v) {
  //...
  try { // exceptions here are handled by the handler defined below
    Vector v(-27);
  } catch (std::length_error &err) {
    //... handle negative size...
    std::cerr << "test failed: length error\n" << '\n';
    throw; // rethrow
  } catch (std::bad_alloc &err) {
    std::terminate();
  }
  //...
}

void user(int sz) noexcept {
  Vector v(sz);
  std::iota(&v[0], &v[sz], 1);
  std::cout << v[sz] << "\n";
}

int main() {
  Vector v(int(5));

  for (int i = 0; i != v.size(); ++i) {
    v[i] = i;
  }
  std::cout << sqrt_sum(v);
  f(v);
  user(5);
  test(v);
}
