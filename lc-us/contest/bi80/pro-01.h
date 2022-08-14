#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  bool strongPasswordCheckerII(string password) {
    int n = password.size();
    if (n < 8) return false;
    bool lower_case = false;
    bool upper_case = false;
    bool digit = false;
    bool special_char = false;
    for (int i = 0; i < n; i++) {
      if (islower(password[i])) lower_case = true;
      if (isupper(password[i])) upper_case = true;
      if (isdigit(password[i])) digit = true;
      if (!islower(password[i]) && !isupper(password[i]) && !isdigit(password[i])) special_char = true;
      if (i > 0) {
        if (password[i] == password[i - 1]) {
          return false;
        }
      }
    }
    return lower_case && upper_case && digit && special_char;
  }
};