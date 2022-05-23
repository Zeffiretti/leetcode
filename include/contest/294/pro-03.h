#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

class Solution {
 public:
  int minimumLines(vector<vector<int>> &stockPrices) {
    if (stockPrices.size() == 1) {
      return 0;
    }
    if (stockPrices.size() == 2) {
      return 1;
    }
    sort(stockPrices.begin(), stockPrices.end());
    map<double, set<double>> lines;
    double diff = (stockPrices[1][1] - stockPrices[0][1]) * 1.0 / (stockPrices[1][0] - stockPrices[0][0]);
    double y_offset = stockPrices[1][1] - diff * 1.0 * stockPrices[1][0];
    lines[diff].insert(y_offset);
    int res = 1;
    for (int i = 2; i < stockPrices.size(); ++i) {
      diff = (stockPrices[i][1] - stockPrices[i - 1][1]) * 1.0 / (stockPrices[i][0] - stockPrices[i - 1][0]);
      y_offset = stockPrices[i][1] - diff * 1.0 * stockPrices[i][0];
      if (lines.find(diff) == lines.end()) {
        lines[diff].insert(y_offset);
        res++;
      } else {
        if (lines[diff].find(y_offset) == lines[diff].end()) {
          lines[diff].insert(y_offset);
          res++;
        }
      }
    }
    return res;
  }
};