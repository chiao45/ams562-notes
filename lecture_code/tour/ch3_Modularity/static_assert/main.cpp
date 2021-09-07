

constexpr double C = 299792.458; // km/s

void f(double speed) {
  constexpr double local_max = 160.0 / (60 * 60);

  static_assert(local_max < C, "can't go that fast");
}

int main() {
  const double val = 2;
  const double my_s = 2 * C;

  f(my_s);
}
