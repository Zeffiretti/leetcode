#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#include "jobs/netease/minafterops.h"
#include "jobs/netease/samenumber.h"
#include "jobs/netease/strconstruct.h"
#include "jobs/netease/weightsum.h"

int main(int argc, char** argv) {
  int n;
  std::cin >> n;
  std::vector<int> node_weights(n + 1);
  for (int i = 1; i < n; ++i) {
    std::cin >> node_weights[i];
  }
  std::vector<std::vector<int>> graph(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  init(n);
  weight(graph, 1, node_weights);
  std::cout << sum_of_weight << std::endl;
  return 0;
}