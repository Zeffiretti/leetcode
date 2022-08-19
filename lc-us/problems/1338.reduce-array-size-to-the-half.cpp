/*
 * @lc app=leetcode id=1338 lang=cpp
 *
 * [1338] Reduce Array Size to The Half
 */
#include <vector>
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int minSetSize(vector<int>& arr) {
    map<int, int> index_map;
    vector<vector<int>> lens;
    for (int& i : arr) {
      if (index_map.find(i) == index_map.end()) {
        index_map[i] = lens.size();
        lens.push_back({i, 1});
      } else {
        lens[index_map[i]][1]++;
      }
    }
    sort(lens.begin(), lens.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] > b[1]; });
    int ans = 0;
    int sum = 0;
    for (auto& len : lens) {
      sum += len[1];
      ans++;
      if (sum >= arr.size() / 2) break;
    }
    return ans;
  }
};
// @lc code=end
