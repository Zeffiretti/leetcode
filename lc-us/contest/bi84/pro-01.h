#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
    vector<vector<int>> result;
    vector<int> item(1001, 0);
    for (auto& i : items1) {
      item[i[0]] += i[1];
    }
    for (auto& i : items2) {
      item[i[0]] += i[1];
    }
    for (int i = 1; i <= 1000; ++i) {
      if (item[i] > 0) {
        result.push_back({i, item[i]});
      }
    }
    return result;
  }
};