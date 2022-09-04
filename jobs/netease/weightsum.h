#ifndef JOBS_NETEASE_WEIGHTSUM
#define JOBS_NETEASE_WEIGHTSUM

#include <iostream>
#include <map>
#include <set>
#include <vector>

const int kMod = 1000000007;
using ll = long long;
ll sum_of_weight = 0;
std::vector<bool> visited;
std::vector<int> tree_weights;
std::map<int, std::set<int>> division_set;

void buildDivision(int x) {
  for (int i = 1; i * i <= x; ++i) {
    for (int j = i; j * i <= x; ++j) {
      if (i * j == x) {
        division_set[x].insert(i);
        if (i != j) {
          division_set[x].insert(j);
        }
      }
    }
  }
}

void init(int n) {
  visited = std::vector<bool>(n + 1, false);
  tree_weights = std::vector<int>(n + 1, 0);
}

ll weight(const std::vector<std::vector<int>>& graph, int node, const std::vector<int>& node_weights) {
  if (visited[node]) return tree_weights[node];
  ll res = 1;
  for (int i = 0; i < graph[node].size(); ++i) {
    int next_node = graph[node][i];
    visited[next_node] = true;
    res = (res * weight(graph, next_node, node_weights));
  }
  tree_weights[node] = res;
  sum_of_weight = division_set[sum_of_weight + res * node_weights[node]].size() % kMod;
  return res;
}

#endif /* JOBS_NETEASE_WEIGHTSUM */
