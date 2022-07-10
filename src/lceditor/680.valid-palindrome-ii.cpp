/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  bool isPalindrome(string s, int l, int r) {
    while (l < r) {
      if (s[l] != s[r]) return false;
      l++;
      r--;
    }
    return true;
  }
  bool validPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left <= right) {
      if (s[left] != s[right]) {
        return isPalindrome(s, left + 1, right) ||
               isPalindrome(s, left, right - 1);
      }
      left++;
      right--;
    }
    return true;
  }
};
// @lc code=end

