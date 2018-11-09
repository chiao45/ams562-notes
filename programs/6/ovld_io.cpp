// This is a demo for understanding how to
// overload output/input operators.

#include <iostream>

class MyInt {
 public:
  MyInt() { _v = 0; }
  MyInt(int v) { _v = v; }
  int &val() { return _v; }
  const int &val() const { return _v; }

 private:
  int _v;
};

// overloading output operator
std::ostream &operator<<(std::ostream &out, const MyInt &i) {
  out << i.val();  // write to output buffer
  return out;
}

// overload input operator
// MyInt must be pass by reference (PBR)
std::istream &operator>>(std::istream &in, MyInt &i) {
  in >> i.val();  // the first val is called
  return in;
}

int main() {
  MyInt i;
  std::cout << "Please enter an integer: ";
  std::cin >> i;
  std::cout << "You just entered " << i << '\n';
  return 0;
}
