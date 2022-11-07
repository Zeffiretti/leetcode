#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> exchange(vector<int>& nums) {
    vector<int> res(nums.size());
    int left = 0, right = nums.size() - 1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] % 2 == 0) {
        res[right--] = nums[i];
      } else {
        res[left++] = nums[i];
      }
    }
    return res;
  }
};