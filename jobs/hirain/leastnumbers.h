#ifndef JOBS_HIRAIN_LEASTNUMBERS
#define JOBS_HIRAIN_LEASTNUMBERS
#include <algorithm>
#include <vector>

namespace pro2 {
class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param input int整型vector
   * @param k int整型
   * @return int整型vector
   */
  std::vector<int> getLeastNumbers(std::vector<int>& input, int k) {
    // write code here
    std::vector<int> result;
    if (k == 0) {
      return result;
    }
    std::sort(input.begin(), input.end());
    int i = 0;
    while (result.size() < k) {
      if (result.empty() || result.back() != input[i]) {
        result.push_back(input[i]);
      }
      ++i;
    }
    return result;
  }
};
}  // namespace pro2

#endif /* JOBS_HIRAIN_LEASTNUMBERS */
