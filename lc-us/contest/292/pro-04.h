#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool hasValidPath(vector<vector<char>>& grid) { return hasValidPath(grid, 0, 0, 0); }
  bool hasValidPath(vector<vector<char>>& grid, int par_left, int i, int j) {
    if (par_left < 0) return false;
    int m = grid.size();
    int n = grid[0].size();
    if (i == m - 1 && j == n - 1) {
      if (grid[i][j] == ')') {
        return par_left == 1;
      }
      return false;
    }
    if (i == m - 1) {
      if (grid[i][j] == ')') {
        par_left--;
      } else {
        par_left++;
      }
      return hasValidPath(grid, par_left, i, j + 1);
    }
    if (j == n - 1) {
      if (grid[i][j] == ')') {
        par_left--;
      } else {
        par_left++;
      }
      return hasValidPath(grid, par_left, i + 1, j);
    }
    if (grid[i][j] == ')') {
      par_left--;
    } else {
      par_left++;
    }
    return hasValidPath(grid, par_left, i + 1, j) || hasValidPath(grid, par_left, i, j + 1);
  }
};
