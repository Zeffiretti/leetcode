/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);
    for (auto& pre : prerequisites) {
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
      q.pop();
      ++count;
      for (auto& next : graph[cur]) {
        --indegree[next];
        if (indegree[next] == 0) {
          q.push(next);
        }
      }
    }
    return count == numCourses;
  }
};
// @lc code=end
