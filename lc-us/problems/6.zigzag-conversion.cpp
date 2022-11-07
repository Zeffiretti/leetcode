/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  string convert(string s, int numRows) {
    int size = s.size();
    if (numRows == 1) {
      return s;
    }
    int period = 2 * numRows - 2;
    int loop = size / period;
    int remainder = size % period;
    string ret;
    ret.clear();
    for (int i = 0; i < numRows; ++i) {  // ith row
      int ch = 2;                        // 2 characters per loop
      if (i == 0 || i == numRows - 1) {
        ch = 1;
      }
      int ext = 0;
      if (remainder > i) {
        ext++;
      }
      if (remainder > numRows - 2 + numRows - i) {
        ext++;
      }
      ext = min(ext, ch);
      // int cols = ch * loop + ext;
      // printf("%d, ", cols);
      // 0th row: col=period+remainder/1
      for (int j = 0; j < loop; ++j) {
        int start = j * period;
        ret.push_back(s[start + i]);
        if (ch == 2) {
          ret.push_back(s[start - i + period]);
        }
      }
      // extra character
      int start = loop * period;

      if (ext > 0) {
        ret.push_back(s[start + i]);
        if (ext > 1) {
          ret.push_back(s[start + period - i]);
        }
      }
    }
    return ret;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  Solution s;
  string st = "ABC";
  auto ss = s.convert(st, 3);
  cout << ss.c_str() << endl;
  return 0;
}