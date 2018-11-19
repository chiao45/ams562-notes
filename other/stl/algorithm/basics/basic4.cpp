// In this example, we will learn linear searching

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

// size of vector
#define N 20

int main(int argc, char const *argv[]) {

  //
  // toy
  std::vector<int> v(N);
  for (auto it = v.begin(); it != v.end(); ++it)
    *it = std::rand() % 100;

  //
  // print out the vector
  std::cout << "the simple random vector is: ";
  for (int i : v)
    std::cout << i << ' ';
  std::cout << '\n';

  //
  // first if we have 5
  // find(begin, end, value)
  auto it5 = std::find(v.begin(), v.end(), 5);
  if (it5 != v.end())
    std::cout << "v contains 5 in position " << it5 - v.begin() << '\n';
  else
    std::cout << "v doesn't contains 5 in position\n";

  //
  // count number of 10
  // count(begin, end, value)
  int n = std::count(v.begin(), v.end(), 10);
  std::cout << "v contains " << n << " 10s\n";

  //
  // now using string (yup, string is a pre-built container)
  // for searching
  std::string msg = "happy thanksgiving!";
  std::string user_guess;
  std::cout << "enter a word:";
  std::cin >> user_guess;

  //
  // searching msg that to check if it has user_guess
  auto it =
      std::search(msg.begin(), msg.end(), user_guess.begin(), user_guess.end());
  if (it != msg.end())
    std::cout << "you got the word **" << user_guess << "** in [" << msg
              << "]\n";
  else
    std::cout << "sorry, you didn't get the word, the pattern is: [" << msg
              << "]\n";
  return 0;
}
