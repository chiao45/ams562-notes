// version 1

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>

// this one by doing smart reordering

void gemm(const int n, const std::vector<double> &a,
          const std::vector<double> &b, std::vector<double> &c) {
  // first fill c with zeros
  std::fill(c.begin(), c.end(), 0.0);

  for (int i = 0; i < n; ++i) {
    const int in = i * n;
    for (int j = 0; j < n; ++j) {
      // get a_ij first
      // then advance c and b
      const double a_ij = a[in + j];
      for (int k = 0; k < n; ++k) {
        c[in + k] += a_ij * b[j * n + k];
      }
    }
  }
}

int main(int argc, char *argv[]) {
  // N is the system size, run is how many times we want
  int N = 512;
  if (argc > 1) N = std::atoi(argv[1]);
  int run = 20;
  if (argc > 2) run = std::atoi(argv[2]);

  std::mt19937 eng(std::time(0));
  std::uniform_real_distribution<double> dist(0.0, 1.0);

  auto gen_rand = [&]() { return dist(eng); };

  std::vector<double> a(N * N);
  std::vector<double> b(N * N);
  std::vector<double> c(N * N);

  // use generate to fill random values
  std::generate(a.begin(), a.end(), gen_rand);
  std::generate(b.begin(), b.end(), gen_rand);

  auto start = std::chrono::system_clock::now();  // start timer

  for (int step = 0; step < run; ++step) gemm(N, a, b, c);

  auto end = std::chrono::system_clock::now();       // end timer
  std::chrono::duration<double> secs = end - start;  // compute wtime

  std::cout << "version III: total time: " << secs.count()
            << "s, avg: " << secs.count() / run << "s.\n";
}