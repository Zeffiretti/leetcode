#ifndef JOBS_MICROSOFT_CONSUBSTR
#define JOBS_MICROSOFT_CONSUBSTR

#include <cmath>
#include <string>
#include <vector>

#ifndef INT_MAX
#  define INT_MAX 2147483647
#endif

namespace consubstr {
int solution(std::string& s) {
  // write your code in C++ (g++ 6.2.0)
  int size = std::pow(2, 27);
  std::vector<int> pos(1 << 26, -1);
  pos[0] = 0;
  int status = 0, ans = 0;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    int letter = s[i] - 'a';
    status ^= (1 << letter);
    if (~pos[status]) {
      ans = std::max(ans, i + 1 - pos[status]);
    } else {
      pos[status] = i + 1;
    }
  }
  return ans;
}
}  // namespace consubstr

#endif /* JOBS_MICROSOFT_CONSUBSTR */
