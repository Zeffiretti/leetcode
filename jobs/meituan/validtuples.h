#ifndef JOBS_MEITUAN_VALIDTUPLES
#define JOBS_MEITUAN_VALIDTUPLES
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
void validTuples() {
  int n;
  cin >> n;
  vector<int> nums(n);
  int res = 0;
  map<int, vector<int>> m;
  bool is_all_zero = true;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    if (nums[i] != 0) {
      is_all_zero = false;
    }
    m[nums[i]].push_back(i);
  }
  if (is_all_zero) {
    long long res_ = n;
    res_ *= n - 1;
    res_ *= n - 2;
    res_ /= 6;
    cout << res_ << endl;
    return;
  }
  for (int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      int ak = 3 * nums[j] - nums[i];
      if (m.find(ak) != m.end()) {
        vector<int> values = m[ak];
        int idx = values.size() - 1;
        while (idx >= 0 && values[idx] > j) {
          res++;
          idx--;
        }
      }
    }
  }
  cout << res << endl;
}

#endif /* JOBS_MEITUAN_VALIDTUPLES */
