#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <stdio.h>

class Solution {
 public:
#define ll long long
  string discountPrices(string sentence, int discount) {
    string res;
    for (int i = 0; i < sentence.size(); ++i) {
      res += sentence[i];
      if (sentence[i] == '$') {
        if (i == 0 || sentence[i - 1] == ' ') {
          int tmp_i = i;
          i++;
          ll price = 0;
          bool is_price = false;
          while (i < sentence.size() && sentence[i] >= '0' && sentence[i] <= '9') {
            is_price = true;
            price = price * 10 + (sentence[i] - '0');
            i++;
          }
          if (i != sentence.size() && (sentence[i] != ' ')) {
            is_price = false;
          }
          if (is_price) {
            double new_price = price * (1 - discount / 100.0);
            // new_price 四舍五入保留两位小数
            new_price = round(new_price * 100) / 100;
            char tmp[20];
            sprintf(tmp, "%.2f", new_price);
            res += tmp;
          } else {
            res += sentence.substr(tmp_i + 1, i - tmp_i - 1);
          }
          i--;
        }
      }
    }
    return res;
  }
};