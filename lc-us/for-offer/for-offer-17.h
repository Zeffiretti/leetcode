#include <cmath>
#include <vector>

class Solution {
 public:
  std::vector<int> printNumbers(int n) {
    // print numbers from 1 to pow(10, n) - 1
    std::vector<int> res;
    if (n == 0) {
      return res;
    }
    int pow10 = std::pow(10, n);
    for (int i = 0; i < pow10; i++) {
      res.push_back(i);
    }
    return res;
  }
};