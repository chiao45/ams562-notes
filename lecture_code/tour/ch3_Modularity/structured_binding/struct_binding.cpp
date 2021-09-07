#include <iostream>
#include <map>
#include <string>

struct Entry {
  std::string name;
  int value;
};

Entry read_entry(std::istream& is) {
  std::string s;
  int i;
  is >> s >> i;
  return {s, i};
}

void incr(map<string, int>& m) {
  for (auto& [key, value] : m) {
    ++value;
  }
}

int main() {
  auto e = read_entry(std::cin);

  std::cout << "{" << e.name << "," << e.value << "}\n";
  // we can also unpack into local variables

  auto [name, val] = read_entry(std::cin);
  std::cout << "{" << name << "," << val << "}\n";

  std::map<std::string, int> m{{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};
  for (const auto [key, value] : m) {
    std::cout << "{" << key << "," << value << "}\n";
  }
}
