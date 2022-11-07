#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  bool digitCount(string num) {
    vector<int> count(10, 0);
    for (int i = 0; i < num.size(); ++i) {
      count[num[i] - '0']++;
    }
    for (int i = 0; i < num.size(); ++i) {
      if (count[i] != num[i] - '0') return false;
    }
    return true;
  }
};