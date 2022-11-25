#include <unordered_map>
#include <vector>

class Solution {
 public:
  int findRepeatNumber(const std::vector<int>& nums) {
    std::vector<int> count(nums.size(), 0);
    for (auto num : nums) {
      count[num]++;
      if (count[num] > 1) {
        return num;
      }
    }
    return -1;
  }
};