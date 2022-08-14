#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    vector<vector<int>> res(grid.size() - 2, vector<int>(grid[0].size() - 2, 0));
    for (int i = 1; i < grid.size() - 1; i++) {
      for (int j = 1; j < grid[0].size() - 1; j++) {
        for (int m = i - 1; m <= i + 1; m++) {
          for (int n = j - 1; n <= j + 1; n++) {
            res[i - 1][j - 1] = max(res[i - 1][j - 1], grid[m][n]);
          }
        }
      }
    }
    return res;
  }
};