#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include "jobs/360/dnafix.h"
#include "jobs/360/paveroad.h"
#include "jobs/360/reorganize.h"

#define UNUSED(X) (void)(X)

int main(int argc, char** argv) {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> weights(n, std::vector<int>(n, 0));
  std::vector<std::vector<int>> graph(n);
  std::vector<int> uis(m), vis(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> uis[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cin >> vis[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cin >> weights[uis[i] - 1][vis[i] - 1];
    weights[vis[i] - 1][uis[i] - 1] = weights[uis[i] - 1][vis[i] - 1];
    graph[uis[i] - 1].push_back(vis[i] - 1);
    graph[vis[i] - 1].push_back(uis[i] - 1);
  }
  std::vector<bool> visited(n, false);
  std::priority_queue<std::vector<int>> pqs;
  visited[0] = true;
  for (auto node : graph[0]) {
    pqs.push({-weights[0][node], 0, node});
  }
  int res = 0;
  while (!pqs.empty()) {
    while (!pqs.empty() && visited[pqs.top()[2]]) {
      pqs.pop();
    }
    if (pqs.empty()) {
      break;
    }
    res -= pqs.top()[0];
    int n = pqs.top()[2];
    visited[n] = true;
    pqs.pop();
    for (auto node : graph[n]) {
      pqs.push({-weights[n][node], n, node});
    }
  }
  std::cout << res << std::endl;
}