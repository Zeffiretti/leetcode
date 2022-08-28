#ifndef JOBS_NETEASE_CARPET
#define JOBS_NETEASE_CARPET

#include <iostream>
#include <vector>

void carpet() {
  int T;
  std::cin >> T;
  for (int _t = 0; _t < T; ++_t) {
    int n, m;
    std::cin >> n >> m;
    char carpet[n][n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        std::cin >> carpet[i][j];
      }
    }
    char results[m][m];
    int res_center_x = m / 2, res_center_y = m / 2;
    int carpet_x = n / 2, carpet_y = n / 2;
    // left top
    for (int i = res_center_x; i >= 0; --i) {
      for (int j = res_center_y; j >= 0; --j) {
        results[i][j] = carpet[carpet_x][carpet_y];
        carpet_y--;
        if (carpet_y < 0) {
          carpet_y = n - 1;
        }
      }
      carpet_y = n - 1;
      carpet_x--;
      if (carpet_x < 0) {
        carpet_x = n - 1;
      }
    }
    for (int i = res_center_x + 1; i < m; ++i) {
      for (int j = 0; j <= res_center_y; ++j) {
        results[i][j] = results[m - i - 1][j];
      }
    }
    for (int i = 0; i <= res_center_x; ++i) {
      for (int j = res_center_y; j < m; ++j) {
        results[i][j] = results[i][m - j - 1];
      }
    }
    for (int i = res_center_x; i < m; ++i) {
      for (int j = res_center_y; j < m; ++j) {
        results[i][j] = results[m - i - 1][m - j - 1];
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        std::cout << results[i][j];
      }
      std::cout << std::endl;
    }
  }
}

#endif /* JOBS_NETEASE_CARPET */
