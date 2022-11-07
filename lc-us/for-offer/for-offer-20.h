#include <string>

class Solution {
 public:
  bool isNumber(string s) {
    int index = 0;
    while (index < s.size() && s[index] == ' ') {  // jump over leading spaces
      index++;
    }
    // remove the last spaces
    int len = s.size();
    while (s[len - 1] == ' ') {
      len--;
    }
    // s = s.substr(index, len - index);
    if (s[index] == '+' || s[index] == '-') {
      index++;
    }
    if (index >= len) return false;
    // find whether there are 'e' or 'E'
    int e_index = -1;
    for (int i = index; i < len; i++) {
      if (s[i] == 'e' || s[i] == 'E') {
        if (e_index != -1) {
          return false;  // there are more than one 'e' or 'E'
        } else {
          e_index = i;
        }
      }
    }
    if (e_index == index || e_index == len - 1) {
      return false;
    }
    // check whether it is a number before 'e'
    bool pre_digit = false;   // whether there is at least one number before '.'
    bool post_digit = false;  // whether there is at least one number after '.'
    if (e_index == -1) {
      int dot_index = -1;
      for (int i = index; i < len; i++) {
        if (s[i] == '.') {
          if (dot_index != -1) {
            return false;  // there are more than one '.'
          } else {
            dot_index = i;
          }
        } else if (s[i] < '0' || s[i] > '9') {
          return false;  // there is a non-digit character
        } else {
          if (dot_index == -1) {
            pre_digit = true;
          } else {
            post_digit = true;
          }
        }
      }
      if (dot_index == len - 1) {  // there is no digit after '.'
        if (!pre_digit) {
          return false;
        }
      }
    } else {
      int dot_index = -1;
      for (int i = index; i < e_index; i++) {
        if (s[i] == '.') {
          if (dot_index != -1) {
            return false;  // there are more than one '.'
          } else {
            dot_index = i;
          }
        } else if (s[i] < '0' || s[i] > '9') {
          return false;  // there is a non-digit character
        } else {
          if (dot_index == -1) {
            pre_digit = true;
          } else {
            post_digit = true;
          }
        }
      }
      if (dot_index == e_index - 1) {  // there is no digit after '.'
        if (!pre_digit) {
          return false;
        }
      }
    }
    // check whether it is an integer after 'e'
    if (e_index != -1) {
      int index = e_index + 1;
      if (s[index] == '+' || s[index] == '-') {
        index++;
      }
      if (index == len) return false;
      for (int i = index; i < len; i++) {
        if (s[i] < '0' || s[i] > '9') {
          return false;  // there is a non-digit character
        }
      }
    }
    return true;
  }
};