#include "customer.hpp"
#include <iostream>
#include <type_traits>
#include <utility>
#include <vector>

class Person {
public:
  std::string first;
  std::string last;
  std::string name;

public:
  Person(std::string f, std::string l)
      : first{std::move(f)}, last{std::move(l)} {}
};
enum class Volume { Normal, Loud, LoudPlus };

int main() {
  enum class Color { balck, white, red };
  if (Color::red != Color::white) {
    std::cout << "Red is white" << std::endl;
  }
  auto p = int(20);
  std::cout << p << std::endl;
  return 0;
}
