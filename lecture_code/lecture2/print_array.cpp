#include <iostream>
void print() {
  int v1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (auto x : v1)
    std::cout << x << '\n';
  for (auto x : {'a', 'b', 'c'})
    std::cout << x << '\n';
}

int main() { print(); }
