#include <iostream>
#include <string>
#include <variant>

struct Entry {
  std::string name; // strin is a standsard library type
  std::variant<int *, int> v;
};

// we only use either p or i
void f(Entry *pe) {
  if (std::holds_alternative<int>(pe->v)) {
    std::cout << std::get<int>(pe->v);
  } else {
    std::cout << *std::get<int *>(pe->v);
  }
}

// maintaining the correspondence between a type field (here t)
// and the type held in a union is error prone.
// To avoid erros we can enfornce that correspondence by encapsulating
// the union and the type field in a class and offer access only
// through member functions that use the union correctly.
//
// At the application level, abstractions relying on such tagged unions
// are common and useful.  The use of "naked" unions is best minimized

int main() {
  //
  Entry ei;
  ei.v = 40;

  Entry ep;
  ep.v = new int;
  ep.v = 20;
  //
  Entry *p_ei = &ei;
  Entry *p_ep = &ep;

  std::cout << "Ei = ";
  f(p_ei);
  std::cout << std::endl;
  std::cout << "Ep = ";
  f(p_ep);

  return 0;
}
