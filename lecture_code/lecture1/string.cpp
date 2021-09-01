#include <iostream>
#include <string>

char *add_char_array(char *first, char *last) {
  // copy pointer to first character of first word
  char *together = first;
  // read up until NULL character
  while (*first != '\0') {
    first++;
  }
  // add a space
  *first = ' ';
  first++;

  // read and append character from last into first
  while (*last != '\0') {
    *first = *last;
    last++;
    first++;
  }

  // append a NULL termination character
  *first = 0;

  std::cout << std::endl;
  return together;
}
int main() {

  char fname[128]; // C-style character array
  char lname[128];
  // std::string fname;
  // std::string lname;

  std::cout << "Give me your name" << std::endl;
  std::cin >> fname;
  std::cin >> lname;

  char *full = add_char_array(fname, lname);
  std::cout << "Your name is " << full << std::endl;

  return 0;
}
