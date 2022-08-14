#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "../../utils.h"

using namespace std;

#include <stdio.h>

class Solution {
 public:
  int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    map<int, vector<int>> rows;
    int res = 0;
    for (int i = 0; i < n; i++) {
      rows[grid[i][0]].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
      auto rows_i = rows[grid[0][i]];
      for (int row : rows_i) {
        int index = 0;
        for (; index < n; ++index) {
          if (grid[row][index] != grid[index][i]) {
            break;
          }
        }
        if (index == n) {
          res++;
        }
      }
    }
    return res;
  }
};