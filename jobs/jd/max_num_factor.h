#ifndef JOBS_JD_MAX_NUM_FACTOR
#define JOBS_JD_MAX_NUM_FACTOR
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

std::map<int, std::vector<int>> factors;

void getFactors() {
  for (int i = 1; i <= 100000; ++i) {
    for (int j = i; j * i <= 100000; ++j) {
      factors[i * j].push_back(i);
      factors[i * j].push_back(j);
    }
  }
}

int getMaxNumFactors(const std::vector<int>& nums) {
  std::map<int, int> factor_count;
  getFactors();
  for (auto num : nums) {
    for (auto factor : factors[num]) {
      ++factor_count[factor];
    }
  }
  int max_count = factor_count.size();
  int operation_index = -1;
  for (int i = 0; i < nums.size(); ++i) {
    int num = nums[i];
    auto tmp_count = factor_count;
    for (auto factor : factors[num]) {
      --tmp_count[factor];
      if (tmp_count[factor] == 0) {
        tmp_count.erase(factor);
      }
    }
    for (auto factor : factors[num + 1]) {
      ++tmp_count[factor];
    }
    if (tmp_count.size() > max_count) {
      max_count = tmp_count.size();
      operation_index = i;
    }
  }
  int num = nums[operation_index];
  auto tmp_count = factor_count;
  for (auto factor : factors[num]) {
    --tmp_count[factor];
    if (tmp_count[factor] == 0) {
      tmp_count.erase(factor);
    }
  }
  for (auto factor : factors[num + 1]) {
    ++tmp_count[factor];
  }
  std::queue<int> fac_q;
  std::set<int> factors;
  for (auto it = tmp_count.begin(); it != tmp_count.end(); ++it) {
    factor_count.insert(*it);
    fac_q.push(it->first);
  }
  while (!fac_q.empty()) {
    int fac = fac_q.front();
    fac_q.pop();
    for (auto factor : factors) {
      int new_fac = fac * factor;
      if (factor_count.find(new_fac) == factor_count.end()) {
        factor_count[new_fac] = 1;
        fac_q.push(new_fac);
      }
    }
    factors.insert(fac);
  }
  return factor_count.size();
}

#endif /* JOBS_JD_MAX_NUM_FACTOR */
