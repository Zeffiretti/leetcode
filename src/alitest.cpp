#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>
#include <map>
#include "stdio.h"
using namespace std;
#include<stdio.h>
class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param str string字符串
   * @return string字符串
   */
  string compress(string str) {
    // write code here
    string res = "";
    string full_str = "[1|" + str + "]";
    int index = 0;
    int n = full_str.size();
    stack<int> counts;
    stack<string> chars;
    string tmp = "";
    while (index < n) {
      if (full_str[index] == '[') {
        chars.push(tmp);
        index++;
        int num = 0;
        while (full_str[index] != '|') {
          num = num * 10 + (full_str[index] - '0');
          index++;
        }
        counts.push(num);
        tmp = "";
      } else if (full_str[index] == ']') {
        int count = counts.top();
        counts.pop();
        string char_str = chars.top();
        chars.pop();
        for (int i = 0; i < count; i++) {
          char_str += tmp;
        }
        tmp = char_str;
      } else {
        tmp += full_str[index];
      }
      index++;
    }
    cout << tmp << endl;
    return res;
  }
  vector<int> findBuilding(vector<int> &heights) {
    vector<int> res(heights.size(), 0);
    for (int i = 0; i < heights.size(); i++) {
      res[i]++;
      int left = i - 1;
      while (left >= 0 && heights[left] < heights[i]) {
        res[left]++;
        left--;
      }
      if (left >= 0) {
        res[left]++;
      }
      int right = i + 1;
      while (right < heights.size() && heights[right] < heights[i]) {
        res[right]++;
        right++;
      }
      if (right < heights.size()) {
        res[right]++;
      }
    }
    return res;
  }
};
int main(int argc, char **argv) {
  Solution s;
  string str = "HG[3|B[2|CA]]F";
  cout << s.compress(str) << endl;
  vector<int> heights = {5, 3, 8, 3, 2, 5};
  auto res = s.findBuilding(heights);
  for (auto i : res) {
    cout << i << " ";
  }
  return 0;
}