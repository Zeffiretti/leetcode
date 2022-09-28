#include <iostream>
#include <vector>

#include "jobs/tplink/maxsum.h"
#include "jobs/tplink/partition.h"

#define UNUSED(X) (void)(X)

int main(int argc, char** argv) {
  UNUSED(argc);
  UNUSED(argv);
  std::vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
  std::cout << "max sum: " << maxSum(nums) << std::endl;
  std::cout << "can partition to 3 pieces: " << canPartitionNumsToKPieces(nums, 4) << std::endl;
  return 0;
}