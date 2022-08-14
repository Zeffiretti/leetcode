/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    int n = speed.size();
    vector<vector<double> > dp(n, vector<double>(2, 0));
    for (int i = 0; i < n; ++i) {
      dp[i] = {double(position[i]), double(speed[i])};
    }
    sort(dp.begin(), dp.end());
    vector<double> times(n, 0);
    int res = 1;
    for (int i = n - 1; i >= 0; --i) {
      double time = (target - dp[i][0]) / dp[i][1];
      //   cout << "i:" << i << " time:" << time << endl;
      if (i != n - 1) {
        if (time <= times[i + 1]) {
          time = times[i + 1];
        } else {
          res++;
        }
      }
      times[i] = time;
    }
    return res;
  }
};
// @lc code=end

