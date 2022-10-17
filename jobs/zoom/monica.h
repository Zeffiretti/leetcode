#ifndef JOBS_ZOOM_MONICA
#define JOBS_ZOOM_MONICA
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

std::pair<int, int>& maxAfterOperation(int a, int b, char op, int val) {
  static std::pair<int, int> res = std::make_pair(a, b);
  if (op == '+') {
    if (val >= 0) {
      if (a >= b) {
        res.first += val;
      } else {
        res.second += val;
      }
    } else {
      if (a >= b) {
        res.second += val;
      } else {
        res.first += val;
      }
    }
  } else {
    if (val >= 0) {
      if (a >= b) {
        res.second -= val;
      } else {
        res.first -= val;
      }
    } else {
      if (a >= b) {
        res.first -= val;
      } else {
        res.second -= val;
      }
    }
  }
  return res;
}

#endif /* JOBS_ZOOM_MONICA */
