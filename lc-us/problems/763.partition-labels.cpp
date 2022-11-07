/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<int> partitionLabels(string s) {
    vector<int> res;
    vector<int> nums(26, 0);
    vector<int> starts(26, s.size());
    vector<int> ends(26, -1);
    for (int i = 0; i < s.size(); ++i) {
      nums[s[i] - 'a']++;
      starts[s[i] - 'a'] = min(starts[s[i] - 'a'], i);
      ends[s[i] - 'a'] = max(ends[s[i] - 'a'], i);
    }
    vector<vector<int>> intervals;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) {
        intervals.push_back({starts[i], ends[i]});
      }
    }
    for (int i = 0; i < intervals.size(); i++) {
      cout << intervals[i][0] << "," << intervals[i][1] << ". ";
    }
    sort(intervals.begin(), intervals.end());
    int start = intervals[0][0];
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] > end) {
        res.push_back(end - start + 1);
        start = intervals[i][0];
        end = intervals[i][1];
      } else {
        end = max(end, intervals[i][1]);
      }
    }
    res.push_back(end - start + 1);
    return res;
  }
};
// @lc code=end
