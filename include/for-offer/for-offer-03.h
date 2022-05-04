#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int findRepeatNumber(vector<int> &nums) {
    vector<int> count(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
      if (count[nums[i]] == 1) {
        return nums[i];
      }
      count[nums[i]]++;
    }
    return -1;
  }
};