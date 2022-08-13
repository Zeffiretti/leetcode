#ifndef JOBS_MICROSOFT_FRACTIONSUM
#define JOBS_MICROSOFT_FRACTIONSUM
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

namespace fractionsum {
using ll = long long;

int __gcd(int a, int b) {
  if (a == 0) {
    return b;
  }
  return __gcd(b % a, a);
}

void simplify_fraction(int* n, int* d) {
  int gcd = __gcd(*n, *d);
  *n /= gcd;
  *d /= gcd;
}

int solution(vector<int>& numerators, vector<int>& denominators) {
  // write your code in C++ (C++14 (g++ 6.2.0))
  int n_size = numerators.size();
  int res = 0;
  map<vector<int>, int> fraction_map;
  for (int i = 0; i < n_size; ++i) {
    int n = numerators[i], d = denominators[i];
    simplify_fraction(&n, &d);
    // std::cout << "simplify_fraction: " << n << "/" << d << std::endl;
    vector<int> fraction = {n, d};
    fraction_map[fraction]++;
  }
  for (auto it = fraction_map.begin(); it != fraction_map.end(); ++it) {
    int n = it->first[0], d = it->first[1];
    if (d != 2 * n) {
      vector<int> fraction = {d - n, d};
      if (fraction_map.find(fraction) != fraction_map.end()) {
        res += it->second * fraction_map[fraction] % 1000000007;
        fraction_map[fraction] = 0;
      }
    } else {
      res += (it->second) * (it->second - 1) / 2 % 1000000007;
    }
  }
  return res;
}
}  // namespace fractionsum

#endif /* JOBS_MICROSOFT_FRACTIONSUM */
