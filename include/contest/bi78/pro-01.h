#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  int divisorSubstrings(int num, int k) {
    string s_num = to_string(num);
    unordered_set<int> divisors;
    int res = 0;
    for (int i = 0; i < s_num.size() - k; ++i) {
      string sub_str = s_num.substr(i, k);
      cout << sub_str << endl;
      int d = stoi(sub_str);
      if (d == 0) {
        continue;
      }
      if (num % d == 0) {
        if (divisors.find(d) == divisors.end()) {
          divisors.insert(d);
          res++;
        }
      }
    }
    return res;
  }
};