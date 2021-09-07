#include <iostream>
#include <string>

int main() {
  char fname[128] = {"ADRIAN"};  // C-style character array
  char lname[128] = {
      "HURTADO"};  // automatically appends null termination character \0
  std::string dfname = "Stella";
  std::string dlname = "Luna";

  std::cout << "My name is " << fname << " " << lname
            << std::endl;  // reads to null termination charcter
  std::cout << "My dog's name " << dfname << " " << dlname << std::endl;

  std::string full_name = dfname + " " + dlname;
  std::cout << "My dog's name " << full_name << std::endl;

  std::string hello = "\" Hello \""

      return 0;
}
