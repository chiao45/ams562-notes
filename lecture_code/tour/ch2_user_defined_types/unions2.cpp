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

// Since p and i are never used at the same time space is wasted
// You can recover the space by specifyying that both should
// be members of a union like this
union Value {
  int *p;
  int i;
};

class ValueUnion {
private:
  Value v;
  Type t;

public:
  ValueUnion(Type ti, Value vi) : v{vi}, t{ti} {}
};

struct Entry {
  std::string name; // strin is a standsard library type
  Type t;
  Value v;
  ; // use i if t=num
};

// we only use either p or i
void f(Entry *pe) {
  if (pe->t == num)
    std::cout << pe->v.i;
  else {
    std::cout << *pe->v.p;
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
  ei.t = num; // set the Type to num
  ei.v.i = 40;

  Entry ep;
  ep.t = ptr; // set Type
  ep.v.p = new int;
  *ep.v.p = 20;
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
