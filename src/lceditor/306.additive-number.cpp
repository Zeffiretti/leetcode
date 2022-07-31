/*
 * @lc app=leetcode id=306 lang=cpp
 *
 * [306] Additive Number
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  bool isAdditiveNumber(const string& num) {
    int n = num.size();
    for (int i = 1; i <= n / 2; ++i) {
      for (int j = 1; j <= (n - i) / 2; ++j) {
        if (dfs_check(num.substr(0, i), num.substr(i, j), num.substr(i + j))) {
          return true;
        }
      }
    }
    return false;
  }

  bool dfs_check(string num1, string num2, const string& num) {
    if (num1.size() > 1 && num1[0] == '0' || num2.size() > 1 && num2[0] == '0') {
      return false;
    }
    string sum = add(num1, num2);
    if (sum == num) {
      return true;
    }
    if (sum.size() >= num.size() || sum.compare(num.substr(0, sum.size())) != 0) {
      return false;
    }
    return dfs_check(num2, sum, num.substr(sum.size()));
  }

  string add(string num1, string num2) {
    string res;
    int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry != 0) {
      int n1 = i >= 0 ? num1[i--] - '0' : 0;
      int n2 = j >= 0 ? num2[j--] - '0' : 0;
      int sum = n1 + n2 + carry;
      res.push_back(sum % 10 + '0');
      carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
