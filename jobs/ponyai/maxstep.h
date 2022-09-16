#ifndef JOBS_PONYAI_MAXSTEP
#define JOBS_PONYAI_MAXSTEP
#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

std::map<char, std::pair<int, int>> directions = {{'^', {-1, 0}}, {'v', {1, 0}}, {'<', {0, -1}}, {'>', {0, 1}}};
int max_step = 1;

void dfs(const std::vector<std::vector<char>>& graph, int i, int j, int step, std::vector<std::vector<int>>& steps,
         std::vector<std::vector<bool>>& visited) {
  if (i < 0 || i >= graph.size() || j < 0 || j >= graph[0].size() || visited[i][j]) {
    max_step = std::max(max_step, step - 1);
    return;
  }
  steps[i][j] = step;
  visited[i][j] = true;
  dfs(graph, i + directions[graph[i][j]].first, j + directions[graph[i][j]].second, step + 1, steps, visited);
}

int maxStepCount(const std::vector<std::vector<char>>& graph) {
  std::vector<std::vector<int>> steps(graph.size(), std::vector<int>(graph[0].size(), 0));
  std::vector<std::vector<bool>> visited;
  for (int i = 0; i < graph.size(); ++i) {
    for (int j = 0; j < graph[0].size(); ++j) {
      visited = std::vector<std::vector<bool>>(graph.size(), std::vector<bool>(graph[0].size(), false));
      dfs(graph, i, j, 1, steps, visited);
      visited.clear();
    }
  }
  return max_step;
}

#endif /* JOBS_PONYAI_MAXSTEP */
