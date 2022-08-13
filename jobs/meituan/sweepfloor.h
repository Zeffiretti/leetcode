#ifndef JOBS_MEITUAN_SWEEPFLOOR
#define JOBS_MEITUAN_SWEEPFLOOR
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void sweepfloor() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<bool>> is_clean(n, vector<bool>(m, false));
  is_clean[0][0] = true;
  int clean_num = 1;
  int cmd_idx = 0;
  bool is_all_clean = false;
  string cmd;
  cin >> cmd;
  int i = 0, j = 0;
  while (cmd_idx < k && !is_all_clean) {
    char cmd_type = cmd[cmd_idx++];
    if (cmd_type == 'W') {
      if (i > 0) {
        i--;
      }
      if (!is_clean[i][j]) {
        is_clean[i][j] = true;
        clean_num++;
      }
    } else if (cmd_type == 'S') {
      if (i < n - 1) {
        i++;
      }
      if (!is_clean[i][j]) {
        is_clean[i][j] = true;
        clean_num++;
      }
    } else if (cmd_type == 'A') {
      if (j > 0) {
        j--;
      }
      if (!is_clean[i][j]) {
        is_clean[i][j] = true;
        clean_num++;
      }
    } else if (cmd_type == 'D') {
      if (j < m - 1) {
        j++;
      }
      if (!is_clean[i][j]) {
        is_clean[i][j] = true;
        clean_num++;
      }
    }
    if (clean_num == n * m) {
      is_all_clean = true;
    }
  }
  if (!is_all_clean) {
    cout << "No" << endl;
    cout << n * m - clean_num;
  } else {
    cout << "Yes" << endl;
    cout << cmd_idx << endl;
  }
}

#endif /* JOBS_MEITUAN_SWEEPFLOOR */
