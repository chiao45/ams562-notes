// version 1

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>

// this one by doing explicit transpose

void gemm(const int n, const std::vector<double> &a,
          const std::vector<double> &b, std::vector<double> &bt,
          std::vector<double> &c) {
  // first fill c with zeros
  std::fill(c.begin(), c.end(), 0.0);

  // transpose b
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) bt[i * n + j] = b[i + j * n];

  for (int i = 0; i < n; ++i) {
    const int in = i * n;
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < n; ++k) c[in + j] += a[in + k] * bt[j * n + k];
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
  std::vector<double> bt(N * N);

  // use generate to fill random values
  std::generate(a.begin(), a.end(), gen_rand);
  std::generate(b.begin(), b.end(), gen_rand);

  auto start = std::chrono::system_clock::now();  // start timer

  for (int step = 0; step < run; ++step) gemm(N, a, b, bt, c);

  auto end = std::chrono::system_clock::now();       // end timer
  std::chrono::duration<double> secs = end - start;  // compute wtime

  std::cout << "version II: total time: " << secs.count()
            << "s, avg: " << secs.count() / run << "s.\n";
}