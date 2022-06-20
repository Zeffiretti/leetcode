#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

class Solution {
 public:
  int longestSubsequence(string s, int k) {
    int slow = 0, fast = 1;
    int res = 0;
    int num = s[0] - '0';
    while (fast < s.size()) {
      if (s[fast] == '0') {
        num = num * 2;
      } else {
        num = num * 2 + 1;
      }
      while (num > k) {
        // remove the leading bit
        num = num & (1 << (fast - slow - 1));
        slow++;
      }
      res = max(res, fast - slow + 1);
      fast++;
    }
    return res;
  }
};