#ifndef JOBS_360_PAVEROAD
#define JOBS_360_PAVEROAD
#include <climits>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

void bfs(std::vector<std::vector<int>>& graph, std::vector<int>& visited, std::vector<int>& dist, int start) {
  std::set<int> q;
  q.insert(start);
  visited[start] = 1;
  dist[start] = 0;
  while (!q.empty()) {
    int curr = *q.begin();
    q.erase(q.begin());
    for (int node : graph[curr]) {
      if (!visited[node]) {
        visited[node] = 1;
        dist[node] = dist[curr] + 1;
        q.insert(node);
      }
    }
  }
}
#endif /* JOBS_360_PAVEROAD */
