#include <iostream>
#include <vector>

#include "jobs/hirain/islandnum.h"
#include "jobs/hirain/leastnumbers.h"

#define UNUSED(X) (void)(X)

int main(int argc, char** argv) {
  UNUSED(argc);
  UNUSED(argv);

  std::vector<int> nums = {4, 5, 1, 6, 2, 7, 3, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 1};
  pro2::Solution s;
  std::vector<int> result = s.getLeastNumbers(nums, 4);
  for (int i : result) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
