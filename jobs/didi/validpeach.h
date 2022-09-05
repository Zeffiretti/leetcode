#ifndef JOBS_DIDI_VALIDPEACH
#define JOBS_DIDI_VALIDPEACH

#include <algorithm>
#include <iostream>
#include <vector>
using ll = long long;
int maxValidPeaches(std::vector<int>& peaches, int k) {
  // write code here
  // descending order
  std::sort(peaches.begin(), peaches.end(), [](int a, int b) { return a > b; });
  if (peaches[0] == peaches[peaches.size() - 1]) {
    return peaches.size();
  }
  int middle = peaches[peaches.size() / 2];
  ll sum = 0;
  for (int peach : peaches) {
    sum += peach;
  }
  if (peaches[peaches.size() - 1] - middle > middle - peaches[0]) {
    for (int i = 0; i < peaches.size(); ++i) {
      if (peaches[i] * (peaches.size() - i) <= k * sum) {
        return peaches.size() - i;
      }
      sum -= peaches[i];
    }
  } else {
    for (int i = peaches.size() - 1; i >= 0; --i) {
      if ((peaches[0]) * (i + 1) <= k * sum) {
        return i + 1;
      }
      sum -= peaches[i];
    }
  }
  return 0;
}

#endif /* JOBS_DIDI_VALIDPEACH */
