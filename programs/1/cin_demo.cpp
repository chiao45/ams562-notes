// AMS 562, Intro to Scientific Computing with C++
// demo program
// author: Qiao Chen
//
// how to compile:
//    g++ cin_demo.cpp -o cin_demo
// how to run:
//    ./cin_demo

#include <iostream>

int main() {
  // best practice, always indicate the user what to enter
  std::cout << "Please enter your first and last names: ";
  std::string fname, lname;
  // the program will hang here til recieve the user input
  std::cin >> fname >> lname;
  std::cout << "Hello! " << fname << ' ' << lname << std::endl;
  return 0;
}
