#include <vector>
using namespace std;

class Solution {
 public:
  int waysToSplitArray(vector<int>& nums) {
    int sum = 0;
    for (auto num : nums) {
      sum += num;
    }
    int tmpsum = 0;
    int res = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      tmpsum += nums[i];
      if (tmpsum >= sum - tmpsum) {
        res++;
      }
    }
    return res;
  }
};