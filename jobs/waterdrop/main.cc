#include <iostream>
#include <vector>

#include "jobs/waterdrop/uscount.h"

#define UNUSED(X) (void)(X)

int main() {
  int n;
  std::cin >> n;
  std::cout << usCount(n) << std::endl;
  return 0;
}