#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "../../utils.h"

using namespace std;

#include <stdio.h>

class Solution {
 public:
  int maximumSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    map<int, int> m;
    m[sumOfDigits(nums[0])] = 0;
    int res = -1;
    for (int i = 1; i < nums.size(); i++) {
      if (m.find(sumOfDigits(nums[i])) != m.end()) {
        res = max(res, nums[i] + nums[m[sumOfDigits(nums[i])]]);
      }
      m[sumOfDigits(nums[i])] = i;
    }
    return res;
  }

  int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
      sum += num % 10;
      num /= 10;
    }
    return sum;
  }
};