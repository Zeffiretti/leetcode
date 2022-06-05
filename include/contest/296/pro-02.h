#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

#include <stdio.h>

class Solution {
 public:
  int partitionArray(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int slow = 0, fast = 0;
    int res = 0;
    while (fast < nums.size()) {
      if (nums[fast] - nums[slow] > k) {
        slow = fast;
        res++;
      }
      fast++;
    }
    return res;
  }
};