#ifndef JOBS_JIDU_FINDODDNUMBER
#define JOBS_JIDU_FINDODDNUMBER
#include <vector>
using namespace std;
class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param arr int整型vector
   * @return int整型
   */
  int FindOddNumber(vector<int>& arr) {
    // write code here
    int res = 0;
    for (auto i : arr) {
      res ^= i;
    }
    return res;
  }
};

#endif /* JOBS_JIDU_FINDODDNUMBER */
