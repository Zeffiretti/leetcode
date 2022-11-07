#include <iostream>
#include <vector>

#include "jobs/mobvista/maxform.h"
#include "jobs/mobvista/monosum.h"

#define UNUSED(X) (void)(X)

int main(int argc, char** argv) {
  UNUSED(argc);
  UNUSED(argv);
  int n;
  std::cin >> n;
  std::vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
  }
  std::cout << monoSum(nums) << std::endl;
  return 0;
}
