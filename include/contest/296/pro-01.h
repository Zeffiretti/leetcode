#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int minMaxGame(vector<int> &nums) {
    int n = nums.size();
    while (n > 1) {
      n /= 2;
      int i = 0;
      while (i < n) {
        if (i % 2 == 0) {
          nums[i] = min(nums[2 * i], nums[2 * i + 1]);
        } else {
          nums[i] = max(nums[2 * i], nums[2 * i + 1]);
        }
        i++;
      }
    }
    return nums[0];
  }
};

