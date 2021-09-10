#include "Vector.h"
#include <list>
// Abstract Types
//

class Container {
public:
  virtual double &operator[](int) = 0; // pure virtual function
  virtual int size() const = 0;        // const member function
  virtual ~Container() {}
};

// virtual maybe redefined later from a class derived from this one
//
// =0 syas function is pure virtual
// saying some class derived from Container must define the function
//
// Therefore it is not possible to define an object that is just a container
//
// No constructor
class Vector_container : public Container {
public:
  Vector_container(int s) : v(s) {}
  ~Vector_container() {}

  double &operator[](int i) override { return v[i]; }
  int size() const override { return v.size(); }

private:
  Vector v;
};

class List_container : public Container {
public:
  List_container() {} // empty List
  List_container(std::initializer_list<double> il) : ld{il} {}
  ~List_container() {}

  double &operator[](int i) override;
  int size() const override { return ld.size(); }

private:
  std::list<double> ld;
};

double &List_container::operator[](int i) {
  for (auto &x : ld) {
    if (i == 0)
      return x; // keep moving till you get to zero
    --i;
  }
  throw std::out_of_range{"List container"};
}
