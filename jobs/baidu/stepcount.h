#ifndef JOBS_BAIDU_STEPCOUNT
#define JOBS_BAIDU_STEPCOUNT
#include <climits>
#include <iostream>
#include <utility>
#include <vector>

int minimum_step = INT_MAX;

void dfs(std::vector<std::vector<char>>& map, int i, int j, int cur, std::vector<std::vector<bool>>& visited) {
  if (i == map.size() - 1 && j == map[0].size() - 1) {
    minimum_step = std::min(minimum_step, cur);
    return;
  }
  if (i < 0 || i >= map.size() || j < 0 || j >= map[0].size() || visited[i][j]) {
    return;
  }
  std::vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  visited[i][j] = true;
  if (map[i][j] == 'r') {
    for (auto direction : directions) {
      if (i + direction.first < 0 || j + direction.second < 0 || i + direction.first >= map.size() ||
          j + direction.second >= map[0].size() || map[i + direction.first][j + direction.second] == 'd') {
        continue;
      }
      dfs(map, i + direction.first, j + direction.second, cur + 1, visited);
    }
  }
  if (map[i][j] == 'e') {
    for (auto direction : directions) {
      if (i + direction.first < 0 || j + direction.second < 0 || i + direction.first >= map.size() ||
          j + direction.second >= map[0].size() || map[i + direction.first][j + direction.second] == 'r') {
        continue;
      }
      dfs(map, i + direction.first, j + direction.second, cur + 1, visited);
    }
  }
  if (map[i][j] == 'd') {
    for (auto direction : directions) {
      if (i + direction.first < 0 || j + direction.second < 0 || i + direction.first >= map.size() ||
          j + direction.second >= map[0].size() || map[i + direction.first][j + direction.second] == 'e') {
        continue;
      }
      dfs(map, i + direction.first, j + direction.second, cur + 1, visited);
    }
  }
}

#endif /* JOBS_BAIDU_STEPCOUNT */
