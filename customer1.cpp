#include "customer.hpp"
#include <iostream>
#include <type_traits>
#include <utility>
#include <vector>

class Person {
public:
  std::string first;
  std::string last;
  std::string name = "lz";

public:
  Person(std::string f, std::string l)
      : first{std::move(f)}, last{std::move(l)} {}
  std::string getname() && { return std::move(name); }
  const std::string &getname() const & { return name; }
};

class C {
public:
  void foo() const & { std::cout << "foo() const&\n"; }
  void foo() && { std::cout << "foo() &&\n"; }
  void foo() & { std::cout << "foo()&\n"; };
  void foo() const && { std::cout << "foo() const&&\n"; }
};
int main() {
  C x;
  x.foo();
  C{}.foo();
  std::move(x).foo();

  const C cx;
  cx.foo();
  std::move(cx).foo();
  std::string getString();

  return 0;
}
