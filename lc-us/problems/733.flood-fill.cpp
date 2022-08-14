/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
    dfs(image, visited, sr, sc, image[sr][sc], newColor);
    return image;
  }
  void dfs(vector<vector<int>> &image, vector<vector<bool>> &visited, int sr, int sc, int oldColor, int newColor) {
    if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return;
    if (image[sr][sc] != oldColor) return;
    if (visited[sr][sc]) return;
    image[sr][sc] = newColor;
    visited[sr][sc] = true;
    dfs(image, visited, sr + 1, sc, oldColor, newColor);
    dfs(image, visited, sr - 1, sc, oldColor, newColor);
    dfs(image, visited, sr, sc + 1, oldColor, newColor);
    dfs(image, visited, sr, sc - 1, oldColor, newColor);
  }
};
// @lc code=end

