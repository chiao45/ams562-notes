
import Vector;
#include <cmath>
#include <iostream>

double sqrt_sum(Vector &v) {
  double sum = 0;
  for (int i = 0; i != v.size(); ++i) {
    sum += std::sqrt(v[i]);
    return sum;
  }
}

int main() {

  Vector v(int(5));

  for (int i = 0; i != v.size(); ++i) {
    v[i] = i;
  }
  std::cout << sqrt_sum(v);
}
