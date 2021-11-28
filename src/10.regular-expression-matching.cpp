// @before-stub-for-debug-begin

using namespace std;
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
    return isMatch(s.c_str(), p.c_str());
  }

  bool isMatch(const char *s, const char *p) {
    if (*p == 0) return *s == 0;

    auto first_match = *s && (*s == *p || *p == '.');

    if (*(p + 1) == '*') {
      return isMatch(s, p + 2) || (first_match && isMatch(++s, p));
    } else {
      return first_match && isMatch(++s, ++p);
    }
  }
};
// @lc code=end
int main(int argc, char **argv) {
  Solution ss;
  string s = "aab";
  string p = "c*a*b";
  cout << ss.isMatch(s, p);
  return 0;
}
