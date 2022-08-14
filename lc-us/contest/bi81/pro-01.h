#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  int countAsterisks(string s) {
    int bar_num = 0;
    int asterisk_num = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '|') {
        bar_num++;
      }
      if (s[i] == '*' && bar_num % 2 == 0) {
        asterisk_num++;
      }
    }
    return asterisk_num;
  }
};