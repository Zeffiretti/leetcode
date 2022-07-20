#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, char const* argv[]) {
  int n, k, t;
  cin >> n >> k >> t;
  vector<pair<int, int>> used;
  for (int i = 0; i < t; ++i) {
    int a, b;
    cin >> a >> b;
    used.push_back({a, b});
  }
  sort(used.begin(), used.end());
  vector<int> res(n, k);
  int eat = 0;
  int index = 0;
  priority_queue<int, vector<int>, greater<int>> que;
  for (int i = 0; i < n; ++i) {
    while (index < t && i + 1 >= used[index].first) {
      eat++;
      que.push(used[index].second);
      index++;
    }
    while (!que.empty() && que.top() < i + 1) {
      que.pop();
      eat--;
    }
    res[i] -= eat;
  }
  for (int i = 0; i < n; ++i) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}