#ifndef JOBS_SANGFOR_ATTACKNUM
#define JOBS_SANGFOR_ATTACKNUM

#include <iostream>
#include <string>
#include <vector>

using ll = long long;

ll attackNum(const std::string& operations) {
  ll res = 0;
  std::vector<int> ops_count(operations.size() + 1, 0);
  std::vector<int> w_pos;
  for (int i = 0; i < operations.size(); ++i) {
    if (operations[i] == 's') {
      ops_count[i + 1] = ops_count[i] + 1;
    } else if (operations[i] == 'w') {
      ops_count[i + 1] = ops_count[i];
      w_pos.push_back(i);
    } else {
      ops_count[i + 1] = ops_count[i];
    }
  }
  for (int i = 0; i < operations.size(); ++i) {
    if (operations[i] == 'r') {
      for (int j = 0; j < w_pos.size() && w_pos[j] < i; ++j) {
        res += ops_count[w_pos[j] + 1];
        res = res % static_cast<int>(1e9 + 7);
      }
    }
  }
  return res;
}

#endif /* JOBS_SANGFOR_ATTACKNUM */
