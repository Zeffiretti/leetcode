#ifndef JOBS_360_REORGANIZE
#define JOBS_360_REORGANIZE

#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <vector>

void reorganizeList(std::vector<int>& nums, int i, int descend, int sorted = 0, int sorted_descend = 1) {
  // sort nums[0~i]
  if (i <= sorted) {
    if (descend == sorted_descend) {
      return;
    } else {
      std::reverse(nums.begin(), nums.begin() + i + 1);
      return;
    }
  }
  if (sorted_descend != descend) {
    std::reverse(nums.begin(), nums.begin() + sorted + 1);
  }
  std::list<int> ll(nums.begin(), nums.begin() + sorted + 1);
  if (descend) {
    for (int j = sorted + 1; j <= i; ++j) {
      auto it = ll.begin();
      while (it != ll.end() && *it > nums[j]) {
        it++;
      }
      ll.insert(it, nums[j]);
    }
    auto it = ll.begin();
    int j = 0;
    while (it != ll.end()) {
      nums[j] = *it;
      it++;
      j++;
    }
  } else {
    for (int j = sorted + 1; j <= i; ++j) {
      auto it = ll.begin();
      while (it != ll.end() && *it < nums[j]) {
        it++;
      }
      ll.insert(it, nums[j]);
    }
    auto it = ll.begin();
    int j = 0;
    while (it != ll.end()) {
      nums[j] = *it;
      it++;
      j++;
    }
  }
}

#endif /* JOBS_360_REORGANIZE */
