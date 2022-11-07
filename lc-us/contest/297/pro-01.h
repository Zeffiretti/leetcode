#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  double calculateTax(vector<vector<int>>& brackets, int income) {
    double res = 0;
    int index = 0;
    while (index < brackets.size() && income > brackets[index][0]) {
      index++;
    }
    if (index == 0) {
      res = income * (brackets[index][1] / 100.0);
      return res;
    }
    res += brackets[0][0] * (brackets[0][1] / 100.0);
    for (int i = 1; i < index; i++) {
      res += (brackets[i][0] - brackets[i - 1][0]) * (brackets[i][1] / 100.0);
    }
    res += (income - brackets[index - 1][0]) * (brackets[index][1] / 100.0);
    return res;
  }
};