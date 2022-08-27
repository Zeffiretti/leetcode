#ifndef JOBS_360_DNAFIX
#define JOBS_360_DNAFIX
#include <string>
#include <vector>

namespace dnafix {
int minoperation(const std::string& s1, const std::string& s2) {
  int n = s1.size();
  int a_count = 0, t_count = 0;
  int operation = 0;
  for (int i = 0; i < n; ++i) {
    if (s1[i] == 'A') {
      a_count++;
    } else {
      t_count++;
    }
    if (s2[i] == 'A') {
      a_count--;
    } else {
      t_count--;
    }
    if (s1[i] != s2[i]) {
      operation++;
    }
  }
  if (a_count == 0) {
    return operation / 2 + operation % 2;
  }
  int diff = std::max(a_count, t_count);
  return (operation - diff) / 2 + diff;
}
}  // namespace dnafix

#endif /* JOBS_360_DNAFIX */
