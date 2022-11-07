#include <iostream>
#include <vector>

#include "jobs/3irobotics/waterproblem.h"

#define UNUSED(X) (void)(X)

class A {
 public:
  int method();

 private:
  int m_val;
};

int A::method() {
  static int val = 0;
  return val++;
}

int main(int argc, char** argv) {
  UNUSED(argc);
  UNUSED(argv);
  // WaterField field;
  // std::cout << field.minimumWaterCost() << std::endl;

  // int n;
  // std::cout << "Please enter the number of fields:";
  // std::cin >> n;
  // WaterField field2 = n;
  // std::cout << "Please enter a matrix cost in size of" << n << "*" << n
  //           << ", where costs[i][j] refers the cost to build a pipe from i to j if i!=j, otherwise refers to the cost
  //           "
  //              "to dig a well at i:"
  //           << std::endl;
  // field2.writeCost();
  // std::cout << field2.minimumWaterCost() << std::endl;

  A a;
  std::cout << a.method() << std::endl;
  std::cout << a.method() << std::endl;
  A b;
  std::cout << b.method() << std::endl;
  std::cout << b.method() << std::endl;
  return 0;
}
