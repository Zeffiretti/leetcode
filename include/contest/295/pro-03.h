#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

class Solution {
 public:
  int totalSteps(vector<int> &nums) {
    int res = 0;
    int pre = 0;
    nums.insert(nums.begin(), 0);
    int index = 1;
    int sub_step = 0;
    while (index < nums.size()) {
      if (nums[index] < nums[pre]) {
        if (nums[index] >= nums[index - 1]) {
          sub_step++;
        } else {
          if (index == 2 || nums[index - 1] >= nums[i - 2]) {
            sub_step++;
          }
        }
      } else {
        res = max(res, sub_step);
        sub_step = 0;
        pre = index;
      }
      index++;
    }
    return res;
  }
};