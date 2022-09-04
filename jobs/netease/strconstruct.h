#ifndef JOBS_NETEASE_STRCONSTRUCT
#define JOBS_NETEASE_STRCONSTRUCT

#include <iostream>
#include <string>
#include <vector>

std::vector<int> splitOnes(int k, int t) {
  // split k ones into n groups, such that the sum of each group is t
  if (t == 0) {
    return std::vector<int>(k, 1);
  }
  int n = k - t;
  std::vector<int> res(n, 0);
  int i = 0;
  int accumulate_one = 0;
  while (accumulate_one < k) {
    res[i] += 1;
    accumulate_one += 1;
    i = (i + 1) % n;
  }
  return res;
}

std::string constructString(int n, int k, int t) {
  // write code here
  if (t >= k) return "-1";
  if (k == 0) return std::string(n, '0');
  std::vector<int> ones = splitOnes(k, t);
  std::string res = "";
  int zero_num = 0;
  for (int one_count : ones) {
    res += std::string(one_count, '1');
    res += "0";
    zero_num++;
  }
  zero_num--;
  res = res.substr(0, k + zero_num);
  if (zero_num > n - k) return "-1";
  res += std::string(n - k - zero_num, '0');
  return res;
}

#endif /* JOBS_NETEASE_STRCONSTRUCT */
