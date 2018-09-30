// AMS 562, Intro to Scientific Computing with C++
// demo program
// author: Qiao Chen
//
// how to compile:
//    g++ cmd_inputs.cpp -o cmd_inputs
// how to run:
//    ./cmd_inputs 1
//    ./cmd_inputs 1 1e1

#include <cstdlib>  // for atoi and atof
#include <iostream>

int main(int argc, char *argv[]) {
  // first we want at least one additional argument, which can be
  // converted to integers
  if (argc < 2) {
    // not enough input arguments
    std::cerr << "usage:\n"
              << "\t./exec integer [floating]" << std::endl;
    return 1;  // return fail
  }

  // now, we know that argv[1] is valid
  const int n = std::atoi(argv[1]);

  // you can think this is the default value
  double eps = 1e-2;
  if (argc > 2) {
    // read in the user specified value
    // what will happen if the statement is argc==2?
    eps = std::atof(argv[2]);
  }

  std::cout << "n=" << n << ' ' << "eps=" << eps << std::endl;
  return 0;
}
