// This is the famous hello world program
#include <iostream>

int main() {
  // best practice, always indicate the user what to enter
  std::cout << "Please enter your first and last names: ";
  std::string fname, lname;
  // the program will hang here until receives the user input
  std::cin >> fname >> lname;
  std::cout << "Hello! " << fname << ' ' << lname << std::endl;
  return 0;
}
