#ifndef JOBS_OPPO_FINDSTR
#define JOBS_OPPO_FINDSTR

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   * findStr从反方向查找子串，返回最后一次匹配成功时，子串的偏移位置，如果没有匹配成功返回-1.
   * 如果子串出现'*',则表示匹配任意字符
   * @param str string字符串 待匹配的字符串
   * @param mod string字符串 匹配模式字符串
   * @return int整型
   */
  int findStr(std::string str, std::string mod) {
    // write code here
    std::reverse(mod.begin(), mod.end());
    std::vector<int> kmp_table = kmp(mod);
    // std::reverse(str.begin(), str.end());
    std::cout << str << std::endl;
    // find mod in str
    int i = 0, j = 0;
    while (i < str.size() && j < mod.size()) {
      if (str[i] == mod[j] || mod[j] == '*') {
        ++i;
        ++j;
      } else if (j > 0) {
        j = kmp_table[j - 1];
      } else {
        ++i;
      }
    }
    if (j == mod.size()) {
      return i;
    }
    return -1;
  }

  // 建立kmp表,遇到'*'可以匹配任意字符
  std::vector<int> kmp(const std::string& str) {
    std::vector<int> kmp_table(str.size(), 0);
    int i = 1;
    int j = 0;
    while (i < str.size()) {
      if (str[i] == str[j] || str[i] == '*') {
        kmp_table[i] = j + 1;
        ++i;
        ++j;
      } else if (j > 0) {
        j = kmp_table[j - 1];
      } else {
        ++i;
      }
    }
    return kmp_table;
  }
};

#endif /* JOBS_OPPO_FINDSTR */
