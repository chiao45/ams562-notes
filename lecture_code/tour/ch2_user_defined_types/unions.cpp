#include <iostream>
#include <string>

// Union is a struct in which all members at the same address
// so taht the union occupies only as much space as its largest
// member.  A union can only hold a value for only one member
// at a time.  Example, consider a symbol table entry that
// holds a name and a value.  The value can either
// be a Node* or an int:
//
enum Type { ptr, num }; // a Type can hold values ptr and num

struct Entry {
  std::string name; // strin is a standsard library type
  Type t;
  int *p; // use p if t==ptr
  int i;
  ; // use i if t=num
};

// we only use either p or i
void f(Entry *pe) {
  if (pe->t == num)
    std::cout << pe->i;
  else {
    std::cout << *pe->p;
  }
}

int main() {
  //
  Entry ei;
  ei.t = num; // set the Type to num
  ei.i = 40;

  Entry ep;
  ep.t = ptr; // set Type
  ep.p = new int;
  *ep.p = 20;
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
