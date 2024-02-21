#include <cassert>
#include <iostream>
#include <string>
#include <vector>

int add(int a, int b) { return a + b; }

class Customer {
private:
  std::string name{};
  std::vector<int> values{};

public:
  Customer(const std::string &n) : name{n} { assert(!name.empty()); }
  std::string getName() const { return name; }

  void addValue(int val) { values.push_back(val); }
  friend std::ostream &operator<<(std::ostream &strm, const Customer &cust) {
    strm << '[' << cust.name << ": ";
    for (int val : cust.values) {
      strm << val << ' ';
    }
    strm << ']';
    return strm;
  }
};
