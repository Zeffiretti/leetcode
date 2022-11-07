#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
#define ll long long
  long long countPairs(int n, vector<vector<int>>& edges) {
    vector<bool> visited(n, false);
    vector<vector<int>> adj(n);
    for (auto& e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }
    vector<vector<int>> groups;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        vector<int> group;
        dfs(i, visited, adj, group);
        groups.push_back(group);
      }
    }
    ll res = (ll)(n) * (ll)(n - 1) / 2;
    if (groups.size() == 1) {
      return 0;
    }
    for (int i = 0; i < groups.size(); ++i) {
      res -= groups[i].size() * (ll)(groups[i].size() - 1) / 2;
    }
    return res;
  }
  void dfs(int u, vector<bool>& visited, vector<vector<int>>& adj, vector<int>& group) {
    visited[u] = true;
    group.push_back(u);
    for (auto v : adj[u]) {
      if (!visited[v]) {
        dfs(v, visited, adj, group);
      }
    }
  }
};