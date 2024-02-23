/* #include "customer.hpp" */
/* #include <type_traits> */
/* #include <utility> */
/* #include <vector> */
/**/
/* class Person { */
/* public: */
/*   std::string first; */
/*   std::string last; */
/*   std::string name = "lz"; */
/**/
/* public: */
/*   Person(std::string f, std::string l) */
/*       : first{std::move(f)}, last{std::move(l)} {} */
/*   std::string getname() && { return std::move(name); } */
/*   const std::string &getname() const & { return name; } */
/* }; */
/**/
/* class C { */
/* public: */
/*   void foo() const & { std::cout << "foo() const&\n"; } */
/*   void foo() && { std::cout << "foo() &&\n"; } */
/*   void foo() & { std::cout << "foo()&\n"; }; */
/*   void foo() const && { std::cout << "foo() const&&\n"; } */
/* }; */
/* std::string getString() { return std::string{"123"}; } */
/**/
/* int main() { */
/*   getString() = "hello"; */
/**/
/*   return 0; */
/* } */
#include <iostream>
#include <string>

class MyString {
public:
  MyString(const char *str) : data(str) {}

  // Copy assignment operator with lvalue reference qualifier
  MyString &operator=(const MyString &other) & {
    std::cout << "Using lvalue assignment operator." << std::endl;
    data = other.data;
    return *this;
  }

  void print() const { std::cout << data << std::endl; }

private:
  std::string data;
};

int main() {
  MyString a("Hello");
  MyString b("World");

  // Using lvalue assignment operator
  a = b; // This will work

  // Using lvalue assignment operator on temporary objects will result in a
  // compilation error MyString("NewValue") = b;  // Error
  return 0;
}
