#ifndef JOBS_MEITUAN_MAGICTRANSFER
#define JOBS_MEITUAN_MAGICTRANSFER
#include <algorithm>
#include <iostream>
#include <vector>

void magictransfer() {
  int n, t;
  std::cin >> n >> t;
  std::vector<int> allowed_time(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> allowed_time[i];
  }
  int magic_num = 0;
  int consumed_time = 0;
  std::sort(allowed_time.begin(), allowed_time.end());
  for (int i = 0; i < n; ++i) {
    if (consumed_time + t <= allowed_time[i]) {
      consumed_time += t;
    } else {
      magic_num++;
    }
  }
  std::cout << magic_num << std::endl;
}

#endif /* JOBS_MEITUAN_MAGICTRANSFER */
