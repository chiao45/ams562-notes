// AMS 562, Intro to Scientific Computing with C++
// demo program
// author: Qiao Chen
//
// how to compile:
//    g++ ita_cin.cpp -o ita_cin
// how to run:
//    ./ita_cin

#include <iostream>
#include <string>

int main() {
  std::string input;
  std::string buffer;
  while (true) {
    std::cout << "enter something:";
    std::cin >> input;
    if (input != "break") {
      std::cout << "you entered: " << input << ", the loop will continue\n";
      // clear the buffer in cin in case the user may enter more
      // than a word
      std::getline(std::cin, buffer);
      continue;
    } else {
      std::cout << "bye!\n";
      break;
    }
  }
  return 0;
}
