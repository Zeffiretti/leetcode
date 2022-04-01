/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  string multiply(string num1, string num2) {
    string res = "0";
    if (num1.size() == 1 && num1[0] == '0') {
      return res;
    }
    if (num2.size() == 1 && num2[0] == '0') {
      return res;
    }
    for (int j = num2.size() - 1; j >= 0; --j) {
      string s_mulpty = singleMultiply(num1, num2.substr(j, 1));
      for (int i = j + 1; i < num2.size(); ++i) {
        s_mulpty.push_back('0');
      }
      res = stadd(res, s_mulpty);
    }
    while (!res.empty() && res[0] == '0') {
      res.erase(res.begin());
    }
    if (res.empty()) {
      return "0";
    }
    return res;
  }
  string singleMultiply(string num1, string num2) {
    string res;
    int i = num1.size() - 1;
    int carry = 0;
    for (; i >= 0; --i) {
      int tmp = (num1[i] - '0') * (num2[0] - '0') + carry;
      carry = tmp / 10;
      res.push_back(tmp % 10 + '0');
    }
    if (carry) res.push_back(carry + '0');
    reverse(res.begin(), res.end());
    while (!res.empty() && res[0] == '0') {
      res.erase(res.begin());
    }
    if (res.empty()) {
      return "0";
    }
    return res;
  }
  string stadd(string num1, string num2) {
    string res;
    int i = num1.size() - 1, j = num2.size() - 1;
    int carry = 0;
    for (; i >= 0 && j >= 0; --i, --j) {
      int tmp = num1[i] - '0' + num2[j] - '0' + carry;
      int cur = tmp % 10;
      carry = tmp / 10;
      res.push_back(cur + '0');
    }
    if (i >= 0) {
      for (; i >= 0; --i) {
        int tmp = num1[i] - '0' + carry;
        int cur = tmp % 10;
        carry = tmp / 10;
        res.push_back(cur + '0');
      }
    } else if (j >= 0) {
      for (; j >= 0; --j) {
        int tmp = num2[j] - '0' + carry;
        int cur = tmp % 10;
        carry = tmp / 10;
        res.push_back(cur + '0');
      }
    }
    if (carry > 0) {
      res.push_back(carry + '0');
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
int main(int argc, char const *argv[]) {
  Solution s;
  string ans = s.stadd("0", "0");
  cout << ans << endl;
  cout << s.singleMultiply("723", "0") << endl;
  cout << s.multiply("123", "456") << endl;
  return 0;
}
