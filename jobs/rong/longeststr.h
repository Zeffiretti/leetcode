#ifndef JOBS_RONG_LONGESTSTR
#define JOBS_RONG_LONGESTSTR
#include <iostream>
#include <string>
#include <vector>

using ll = long long;

int longest_weight_substring(const std::string str, const std::vector<int> weights) {
  int res = 0;
  for (int i = 0; i < str.size(); ++i) {
    if (weights[str[i] - 'a'] > 0) {
      res++;
    }
  }
  return res;
}

#endif /* JOBS_RONG_LONGESTSTR */
