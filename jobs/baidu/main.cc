#include <iostream>
#include <string>
#include <vector>

#include "jobs/baidu/baidustr.h"
#include "jobs/baidu/stepcount.h"

#define UNUSED(X) (void)(X)

int main(int argc, char** argv) {
  UNUSED(argc);
  UNUSED(argv);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<char>> map(n, std::vector<char>(m, ' '));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> map[i][j];
    }
  }
  int i = 0, j = 0;
  std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
  dfs(map, i, j, 0, visited);
  std::cout << minimum_step << std::endl;
  return 0;
}
