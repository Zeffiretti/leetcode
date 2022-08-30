#include <iostream>
#include <vector>

#include "jobs/nio/binarysearchtreecount.h"
#include "jobs/nio/stockprices.h"

int main() {
  int n;
  std::cin >> n;
  std::cout << binarySearchTreeCount(n) << std::endl;
  return 0;
}