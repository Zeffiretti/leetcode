#ifndef JOBS_JIDU_HEXTOINT
#define JOBS_JIDU_HEXTOINT
#include <string>
using namespace std;
class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param strHex string字符串 16进制字符串
   * @return int整型
   */
  int HexStr2int(string strHex) {
    // write code here
    int res = 0;
    for (auto i : strHex) {
      res *= 16;
      if (i >= '0' && i <= '9') {
        res += i - '0';
      } else if (i >= 'a' && i <= 'f') {
        res += i - 'a' + 10;
      } else if (i >= 'A' && i <= 'F') {
        res += i - 'A' + 10;
      }
    }
    return res;
  }
};

#endif /* JOBS_JIDU_HEXTOINT */
