// algorithm test file

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <unordered_map>

#include "myalgorithm/myalgorithm.h"

int main(int argc, char **arhv) {
  std::cout << "good" << std::endl;

  // initilize a vector randomly of int
  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // shuffle the vector
  std::random_shuffle(nums.begin(), nums.end());
  // print the vector
  std::cout << "nums: ";
  for (auto i : nums) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  //select the 3rd smallest element
  std::cout << "3rd smallest element: " << mAlg::select(nums, 0, nums.size()-1, 10) << std::endl;
  //sort the nums using heap sort
  mAlg::heapSort(nums);
  // print the sorted vector
  std::cout << "sorted nums: ";
  for (auto i : nums) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}