#include "customer.hpp"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <memory>
#include <random>
#include <utility>

#define LEVEL_DB
class LEVEL_DB A {};
class Person {
public:
  std::string name1 = "1";
  std::string name2 = "2";
  Person() = default;
  Person(const Person &) { std::cout << "copy" << std::endl; }
  /* Person(Person &&) noexcept { std::cout << "move" << std::endl; } */
  Person &operator=(Person &&) = default;
};
int main() {

  auto c1 = std::unique_ptr<Person>();
  auto c2 = std::unique_ptr<Person>();
  auto x = [](auto &a, auto &b) { return a + b; };

  auto pw = std::make_unique<Person>();
  auto func = [pw = std::move(pw)] { return pw->name1; };
  auto func1 = [pw = std::unique_ptr<Person>()] { return pw->name2; };
  std::cout << func() << std::endl;
  std::cout << "-----------------" << std::endl;
  std::cout << pw->name2 << std::endl;
}
