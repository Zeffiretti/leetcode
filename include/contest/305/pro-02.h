#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

#include <stdio.h>

class Solution {
 public:
  int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
    int res = 0;
    set<int> restricted_set(restricted.begin(), restricted.end());
    vector<vector<int>> graph;
    graph.resize(n);
    for (const auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    vector<bool> visited(n, false);
    res += dfs(graph, restricted_set, visited, 0);
    return res;
  }

  int dfs(vector<vector<int>>& graph, set<int>& restricted_set, vector<bool>& visited, int node) {
    if (visited[node] || restricted_set.count(node)) {
      return 0;
    }
    visited[node] = true;
    int res_tmp = 1;
    for (const auto& next : graph[node]) {
      res_tmp += dfs(graph, restricted_set, visited, next);
    }
    return res_tmp;
  }
};