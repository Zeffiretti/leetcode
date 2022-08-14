/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> res;
    unordered_map<int, vector<int>> graph;
    vector<int> indegree(numCourses, 0);
    for (auto &pre : prerequisites) {
      graph[pre[1]].push_back(pre[0]);
      ++indegree[pre[0]];
    }
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }
    int count = 0;
    while (!q.empty()) {
      int cur = q.front();
      res.push_back(cur);
      q.pop();
      ++count;
      for (auto &next : graph[cur]) {
        --indegree[next];
        if (indegree[next] == 0) {
          q.push(next);
        }
      }
    }
    if (count != numCourses) {
      return {};
    }
    return res;
  }
};
// @lc code=end

