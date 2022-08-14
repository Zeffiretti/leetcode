// @before-stub-for-debug-begin
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int j = 1; j < n + 1; j++) {  // 检查s[0]能匹配的位置
      if (p[j - 1] == '*') {
        dp[0][j] = dp[0][j - 2];
      }
    }
    for (int i = 1; i < m + 1; ++i) {
      for (int j = 1; j < n + 1; ++j) {
        if (p[j - 1] == '.') {  // 只要前一个位置能匹配，此处就能匹配
          dp[i][j] = dp[i - 1][j - 1];
        } else if (p[j - 1] != '*') {  // 前一个位置能匹配 && 当前位置能匹配，那就能匹配
          dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
        } else if (p[j - 2] != s[i - 1] && p[j - 2] != '.') {  // 此处的 ‘a*’ 不用匹配
          dp[i][j] = dp[i][j - 2];
        } else {  // 三种情况
          // dp[i][j-1]: 去掉p中的*后前面的元素能匹配
          // dp[i-1][j]: 去掉s中最后一个a(p中*前面的字符)后元素能匹配
          // dp[i][j-2]: 去掉p中的a*后前面的元素能匹配
          // 上面三种情况任有一种即可
          dp[i][j] = dp[i][j - 1] || dp[i - 1][j] || dp[i][j - 2];
        }
      }
    }
    return dp[m][n];
  }
};
// @lc code=end
int main(int argc, char** argv) {
  Solution ss;
  string s = "aab";
  string p = "c*a*b";
  cout << ss.isMatch(s, p);
  return 0;
}
