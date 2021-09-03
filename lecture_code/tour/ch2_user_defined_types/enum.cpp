#include <iostream>
#include <string>
#include <variant>

enum class Color { red, blue, green };
enum class Traffic_light { green, yellow, red };

Traffic_light &operator++(Traffic_light &t) {
  switch (t) {
  case Traffic_light::green:
    return t = Traffic_light::yellow;
  case Traffic_light::yellow:
    return t = Traffic_light::red;
  case Traffic_light::red:
    return t = Traffic_light::green;
  }
  return t;
}

void printLight(const Traffic_light &t) {
  if (t == Traffic_light::green) {
    std::cout << "Green" << std::endl;
  } else if (t == Traffic_light::yellow) {
    std::cout << "Yellow" << std::endl;
  } else if (t == Traffic_light::red) {
    std::cout << "Red" << std::endl;
  } else {
    std::cout << "Flash Who knows" << std::endl;
  }
}

int main() {
  Color col = Color::red;
  Traffic_light light = Traffic_light::red;
  printLight(light);
  ++light;
  printLight(light);
  ++light;
  printLight(light);

  // enumerators are in the scope of their enum class
  // The can be used repeatedly in different enum classes
  // without confusion
  //
  // Enumerations are used to represent a small set of integer
  // values.  They are used to make code more readable
  // and less error-prone
  //
  // The class after enum specifies that an enumeration
  // is strongly typed and that its enumerations are scoped
  //
  // Being seperate types, enum classes help prevent accidental
  // misuses of constants...we can't mix Traffic_light and
  // Color values:
  //
  //
  // Color x = red; eror which red?
  // Color y = Traffic_light::red; red is not a Color
  Color z = Color::red; // allowed in c++ 17
  Color x = Color{5};   // allowed in c++ 17
  Color y{0};
  std::cout << (int)x << std::endl;
  std::cout << (int)z << std::endl;

  return 0;
}
