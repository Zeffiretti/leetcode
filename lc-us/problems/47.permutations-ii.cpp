/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */
#include "utils.h"
// @lc code=start
struct VectorHasher {
  int operator()(const vector<int>& v) const {
    int hash;
    for (int i = 0; i < v.size(); i++) {
      hash = hash * 10 + (v[i] + 10);
    }
    return hash;
  }
};
class Solution {
 public:
  unordered_map<vector<int>, int, VectorHasher> m;
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.empty()) return res;
    vector<int> tmp;
    dfsUnique(nums, tmp, res);
    return res;
  }
  // dfs algorithm for generating unique permutations
  void dfsUnique(vector<int> nums, vector<int>& tmp, vector<vector<int>>& res) {
    if (nums.empty()) {
      if (m.find(tmp) == m.end()) {
        res.push_back(tmp);
        m[tmp] = 1;
      }
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      int val = nums[i];
      nums.erase(nums.begin() + i);
      tmp.push_back(val);
      dfsUnique(nums, tmp, res);
      tmp.pop_back();
      nums.insert(nums.begin() + i, val);
    }
  }
};
// @lc code=end
