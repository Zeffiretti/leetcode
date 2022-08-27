#ifndef JOBS_360_PAVEROAD
#define JOBS_360_PAVEROAD
#include <climits>
#include <iostream>
#include <set>
#include <string>
#include <vector>

class PaveRoad {
 public:
  int solution(const std::vector<int>& sources, const std::vector<int>& destinations, const std::vector<int>& weights,
               int n, int m) {
    num_node = n;
    std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i) {
      graph[sources[i]][destinations[i]] = weights[i];
      graph[destinations[i]][sources[i]] = weights[i];
    }
    // print graph
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        std::cout << graph[i][j] << ",";
      }
      std::cout << std::endl;
    }

    std::set<int> visites_sets;
    for (int i = 1; i <= n; ++i) {
      visites_sets.clear();
      std::cout << "i=" << i << ",";
      dfs(graph, visites_sets, 1, i, 0);
    }
    return cost;
  }

  void dfs(const std::vector<std::vector<int>>& graph, std::set<int>& visited, int visited_node_cnt, int current_node,
           int current_cost) {
    if (visited_node_cnt == num_node) {
      std::cout << "current cost: " << current_cost << std::endl;
      cost = std::min(cost, current_cost);
      return;
    }
    visited.insert(current_node);
    for (int i = 1; i < graph[current_node].size(); ++i) {
      if (visited.find(i) == visited.end() && graph[current_node][i] != 0) {
        dfs(graph, visited, visited_node_cnt + 1, i, current_cost + graph[current_node][i]);
      }
    }
  }

 private:
  int cost = INT_MAX;
  int num_node;
};
#endif /* JOBS_360_PAVEROAD */
