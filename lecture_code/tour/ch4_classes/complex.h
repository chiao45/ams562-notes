

class complex {
  double re, im; // respresentation: two doubles
public:
  complex(double r, double i)
      : re{r}, im{i} {}               // construct complex from two scalars
  complex(double r) : re{r}, im{0} {} // construct complex from one scalar
  complex() : re{0}, im{0} {}         // default complex:{0,0}

  // default constructor
  // we elimate the possiblility of uninitialied variables of type complex

  double real() const { return re; }
  void real(double d) { re = d; }
  double imag() const { return im; }
  void imag(double d) { im = d; }

  // return a reference to this
  complex &operator+=(complex z) {
    re += z.re;
    im += z.re;
    return *this;
  }

  complex &operator-=(complex z) {
    re -= z.re;
    im -= z.re;
    return *this;
  }
  complex &operator*=(complex);
  complex &operator/=(complex);
};
/* simple operations such as constructors += imag() must be implemented
 * without function calls in the generated machine code
 *
 * Functions defined in a class are inlined by default
 *
 * const indicates functions do not modify the object from which they are called
 *
 * const memember functions can be invoked for both const and non-const objects
 *
 * non-const member function can only be invoked for non-const objects
 */
// many Operatrions do not direct access to the representation of complex
//
complex operator+(complex a, complex b) { return a += b; }
complex operator-(complex a, complex b) { return a -= b; }
complex operator-(complex a) { return {-a.real(), -a.imag()}; }
complex operator*(complex a, complex b) { return a *= b; }
complex operator/(complex a, complex b) { return a /= b; }
// *= +- return ref to this... here we return complex so does that become a
// copy of ref?
// Since the argument is passed by value
// the value is copied and we can modify the argument
// without affecting the caller's copy and use the result as a return value!
bool operator==(complex a, complex b) {
  return a.real() == b.real() && a.imag() == b.imag();
}
bool operator!=(complex a, complex b) { return !(a == b); }
complex sqrt(complex); // definitino is elsewhere
