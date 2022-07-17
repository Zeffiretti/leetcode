#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> numberOfPairs(vector<int>& nums) {
    vector<int> res;
    if (nums.size() == 1) {
      res.push_back(0);
      res.push_back(1);
      return res;
    }
    sort(nums.begin(), nums.end());
    int operations = 0;
    int n = nums.size();
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] == nums[i + 1]) {
        operations += 1;
        i++;
        n -= 2;
      }
    }
    res.push_back(operations);
    res.push_back(n);
    return res;
  }
};