#include <string>
using namespace std;

class Solution {
 public:
  string largestGoodInteger(string num) {
    char res = '0' - 1;
    for (int i = 0; i < num.size() - 2; i++) {
      if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
        if (res[0] < num[i]) {
          res = num[i];
        }
      }
    }
    if (res == '0' - 1) {
      // return an empty string
      return "";
    } else {
      return string(3, res);
    }
  }
};
