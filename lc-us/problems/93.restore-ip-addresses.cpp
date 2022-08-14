/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    if (s.size() < 4 || s.size() > 12) return {};
    vector<string> res;
    string tmp;
    dfs(s, 0, tmp, res, 0);
    return res;
  }
  void dfs(string &s, int start, string &cur, vector<string> &res, int dots) {
    if (dots == 4) {
      // cout << "cur is " << cur << endl;
      if (cur.size() == s.size() + 3 && isValidIP(cur)) {
        res.push_back(cur);
      }
      return;
    }
    for (int i = start; i < s.size() - (3 - dots) && i <= start + 3; i++) {
      // from start to i
      auto sub = s.substr(start, i - start + 1);
      // cout << "sub is " << sub << endl;
      auto tmp = cur;
      if (tmp.empty()) {
        tmp = sub;
      } else {
        tmp += "." + sub;
      }
      dfs(s, i + 1, tmp, res, dots + 1);
    }
  }
  bool isValidIP(string &s) {
    // split s with '.'
    vector<string> parts;
    string tmp;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '.') {
        parts.push_back(tmp);
        tmp.clear();
      } else {
        tmp.push_back(s[i]);
      }
    }
    parts.push_back(tmp);
    if (parts.size() != 4) {
      return false;
    }
    for (int i = 0; i < parts.size(); ++i) {
      if (parts[i].size() == 0 || parts[i].size() > 3) {
        return false;
      }
      for (int j = 0; j < parts[i].size(); ++j) {
        if (parts[i][j] < '0' || parts[i][j] > '9') {
          return false;
        }
      }
      // if there are leading zeros in parts[i], the IP is invalid
      if (parts[i][0] == '0' && parts[i].size() > 1) {
        return false;
      }
      if (stoi(parts[i]) > 255) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end


// main function
int main() {
  Solution s;
  string s1 = "25525511135";
  auto ips = s.restoreIpAddresses(s1);
  for (auto ip : ips) {
    cout << ip << endl;
  }
  return 0;
}
