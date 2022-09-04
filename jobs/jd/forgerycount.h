#ifndef JOBS_JD_FORGERYCOUNT
#define JOBS_JD_FORGERYCOUNT
#include <algorithm>
#include <vector>

int countForgery(std::vector<int>& nums) {
  // write code here
  std::sort(nums.begin(), nums.end());
  int real_num = nums[nums.size() - 1];
  // find the first index of real_num, using binary search
  int left = 0;
  int right = nums.size() - 1;
  int mid = 0;
  while (left < right) {
    mid = left + (right - left) / 2;
    if (nums[mid] < real_num) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left;
}
#endif /* JOBS_JD_FORGERYCOUNT */
