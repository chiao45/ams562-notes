// AMS 562, Intro to Scientific Computing with C++
// demo program
// author: Qiao Chen
//
// how to compile:
//    g++ cout_vs_cerr.cpp
// how to run:
//    ./a.out

// include io
#include <iostream>

int main() {
  // write a message to stdout
  std::cout << "This is from cout\n";
  // write something to stderr
  std::cerr << "This is from cerr\n";
  return 0;
}