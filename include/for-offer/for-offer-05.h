#include <string>
using namespace std;
class Solution {
 public:
  string replaceSpace(string s) {
    string res;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        res += "%20";
      } else {
        res += s[i];
      }
    }
    return res;
  }
};