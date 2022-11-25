#include <vector>

class Solution {
 public:
  int movingCount(int m, int n, int k) {
    if (k == 0) return 1;
    std::vector<std::vector<bool>> accessed(m, std::vector<bool>(n, false));
    int count = 0;
    accessed[0][0] = true;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int sum = i / 10 + i % 10 + j / 10 + j % 10;
        if (i == 0) {
          if (j == 0) {
            continue;
          } else {
            if (accessed[i][j - 1] && sum <= k) {
              count++;
              accessed[i][j] = true;
            }
          }
          continue;
        }
        if (j == 0) {
          if (accessed[i - 1][j] && sum <= k) {
            count++;
            accessed[i][j] = true;
          }
          continue;
        }
        if ((accessed[i - 1][j] || accessed[i][j - 1]) && sum <= k) {
          count++;
          accessed[i][j] = true;
        }
      }
    }
    return count;
  }
};