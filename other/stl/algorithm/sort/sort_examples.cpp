// This example shows how to use std::sort from the basis to
// the advanced, which including using functors and lambdas

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

///////////////////////////////////////////////////////
//
// function greater
bool greater(int a, int b) { return a > b; }

//
// functor close to
class Close2 {
public:
  Close2() {}
  //
  // Constructor for capturing value inside the functor
  Close2(int val) : val_(val) {}

  //
  // calleable overloading
  bool operator()(int a, int b) const {
    return std::abs(a - val_) < std::abs(b - val_);
  }

private:
  int val_;
};

//
// random number generator from -100 to 100
int gen_rand100() { return (std::rand() % 200) - 100; }

///////////////////////////////////////////////////////

int main() {
  //
  // first, create our toy
  std::vector<int> v(30);

  //
  // call std::generate
  // generate(first, last, generator)
  std::generate(v.begin(), v.end(), gen_rand100);

  std::cout << "v is:\n";
  for (int i : v)
    std::cout << i << ' ';
  std::cout << '\n';

  //
  // Naive sorting
  std::sort(v.begin(), v.end());

  std::cout << "after naive std::sort, v is:\n";
  for (int i : v)
    std::cout << i << ' ';
  std::cout << '\n';

  //
  // sort the opposite way
  std::sort(v.begin(), v.end(), greater);

  std::cout << "after std::sort with greater, v is:\n";
  for (int i : v)
    std::cout << i << ' ';
  std::cout << '\n';

  //
  // using functor close2 to sort v in terms of abs distance
  // to origin, i.e. zero
  int origin = 0;

  Close2 close2origin(origin);
  std::sort(v.begin(), v.end(), close2origin);

  std::cout << "after std::sort with close2origin, v is:\n";
  for (int i : v)
    std::cout << i << ' ';
  std::cout << '\n';

  //
  // Alternatively, you can construct the functor in place
  // because the functor will be copied locally anyway
  std::sort(v.begin(), v.end(), Close2(origin));

  //
  // You can of course using lambda
  // Syntax: [captures](parameter list){function body}; <- semicolon if you
  // define it
  //
  // For capture:
  //    =, capture by copying, [=]
  //       val names, also by copying [val1, val2, val3]
  //    &, caputure by reference [&]
  //       with val names, [&val1, &val2, &val3]
  //    mixed
  //        [val1, &val2]

  auto close2origin_lmbd = [=](int a, int b) {
    return std::abs(a - origin) < std::abs(b - origin);
  };

  std::sort(v.begin(), v.end(), close2origin_lmbd);

  //
  // or, you can construct lambda in place, note that this time, we will
  // capture origin by its reference
  std::sort(v.begin(), v.end(), [&origin](int a, int b) {
    return std::abs(a - origin) < std::abs(b - origin);
  });
}
