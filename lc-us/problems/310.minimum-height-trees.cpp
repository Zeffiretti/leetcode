/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};
    if (n == 2) return {0, 1};
    vector<vector<int>> graph(n);
    for (auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    vector<int> leaves;
    for (int i = 0; i < n; ++i) {
      if (graph[i].size() == 1) {
        leaves.push_back(i);
      }
    }
    while (n > 2) {
      n -= leaves.size();
      vector<int> newLeaves;
      for (auto leaf : leaves) {
        for (auto neighbor : graph[leaf]) {
          graph[neighbor].erase(find(graph[neighbor].begin(), graph[neighbor].end(), leaf));
          if (graph[neighbor].size() == 1) {
            newLeaves.push_back(neighbor);
          }
        }
      }
      leaves = newLeaves;
    }
    return leaves;
  }
};
// @lc code=end
