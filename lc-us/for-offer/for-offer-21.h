#include <vector>

class Solution {
 public:
  std::vector<int> exchange(const std::vector<int>& nums) {
    std::vector<int> res(nums.size());
    int left = 0, right = nums.size() - 1;
    for (int num : nums) {
      if (num % 2 == 0) {
        res[right--] = num;
      } else {
        res[left++] = num;
      }
    }
    return res;
  }
};