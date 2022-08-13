#ifndef JOBS_MEITUAN_MAGICTRANSFER
#define JOBS_MEITUAN_MAGICTRANSFER
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void magictransfer() {
  int n, t;
  cin >> n >> t;
  vector<int> allowed_time(n);
  for (int i = 0; i < n; ++i) {
    cin >> allowed_time[i];
  }
  int magic_num = 0;
  int consumed_time = 0;
  sort(allowed_time.begin(), allowed_time.end());
  for (int i = 0; i < n; ++i) {
    if (consumed_time + t <= allowed_time[i]) {
      consumed_time += t;
    } else {
      magic_num++;
    }
  }
  cout << magic_num << endl;
}

#endif /* JOBS_MEITUAN_MAGICTRANSFER */
