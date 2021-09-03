// This is the famous hello world program
#include <iostream>

int main() {
  std::string word, sent;
  std::cout << "Enter a word:";
  std::cin >> word;  // read in a word from cin
  std::cout << "The word you just entered is:" << word << std::endl;
  std::cin.ignore();  // ignore '\n'
  std::cout << "Enter a sentence:\n";
  std::getline(std::cin, sent);
  std::cout << "The sentence you entered is:\n" << sent << std::endl;

  return 0;
}
