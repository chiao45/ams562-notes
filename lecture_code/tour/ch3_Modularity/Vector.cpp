// file Vector.cpp
#include "Vector.h"
#include <stdexcept>

Vector::Vector(int s) {
  if (s < 0)
    throw std::length_error{"Vector constructor: negative size"};
  elem = new double[s];
  sz = s;
}
double &Vector::operator[](int i) {
  if (i < 0 || size() <= i) {
    throw std::out_of_range{"Vector::operator[]"};
  }
  return elem[i];
}

const int Vector::size() const { return sz; } // const member function

const int size(const Vector &v) { return v.size(); }
