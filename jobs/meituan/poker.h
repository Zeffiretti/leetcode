#ifndef JOBS_MEITUAN_POKER
#define JOBS_MEITUAN_POKER
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
void poker() {
  int n;
  cin >> n;
  vector<int> cards(n);
  for (int i = 0; i < n; ++i) {
    cin >> cards[i];
  }
  int card_idx = 2;
  vector<int> res(n, 0);
  int i = 0, j = 2;
  while (i < n) {
    res[j] = cards[i];
    ++i;
    for (int m = 0; m < 3; ++m) {
      j++;
      if (j == n) {
        j = 0;
      }
      while (j < n && res[j] != 0) {
        ++j;
      }
      if (j == n) {
        j = 0;
      }
      while (j < n && res[j] != 0) {
        ++j;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << res[i] << " ";
  }
  cout << endl;
}

#endif /* JOBS_MEITUAN_POKER */
