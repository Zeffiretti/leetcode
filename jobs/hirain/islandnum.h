#ifndef JOBS_HIRAIN_ISLANDNUM
#define JOBS_HIRAIN_ISLANDNUM
#include <vector>

namespace pro1 {
class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param grid char字符型vector<vector<>>
   * @return int整型
   */
  int solve(std::vector<std::vector<char> >& grid) {
    // write code here
    int result = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        if (grid[i][j] == '1') {
          ++result;
          dfs(grid, i, j);
        }
      }
    }
    return result;
  }
  void dfs(std::vector<std::vector<char> >& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == '0') {
      return;
    }
    grid[i][j] = '0';
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
  }
};
}  // namespace pro1

#endif /* JOBS_HIRAIN_ISLANDNUM */
