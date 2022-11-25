#include <string>

class Solution {
 public:
  std::string replaceSpace(std::string s) {
    std::string res;
    for (auto ch : s) {
      if (ch == ' ') {
        res += "%20";
      } else {
        res += ch;
      }
    }
    return res;
  }
};