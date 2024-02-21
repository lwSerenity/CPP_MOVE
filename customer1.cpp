#include "customer.hpp"
#include <iostream>
#include <utility>

class Person {
public:
  std::string first;
  std::string last;

public:
  Person(std::string f, std::string l)
      : first{std::move(f)}, last{std::move(l)} {}
};
int main() {
  std::string &&a = "123";
  std::string b = a;
  std::string name1 = "back", name2 = "cook";
  Person p1(std::move(name1), a);
  std::cout << p1.first << " " << p1.last << std::endl;
  std::cout << name1 << " " << name2 << std::endl;

  return 0;
}
