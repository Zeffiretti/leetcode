#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  typedef long long ll;
  int idealArrays(int n, int maxValue) {
    vector<ll> dp(n + 1, 0);
    vector<int> layers;
    dp[0] = 1;
    dp[1] = maxValue;
    for (int i = 1; i <= maxValue; i++) {
      layers.push_back(i);
    }
    for (int i = 2; i <= n; i++) {
      vector<int> new_layers;
      for (int j = 0; j < layers.size(); j++) {
        int num = layers[j];
        int factor = 1;
        while (num * factor <= maxValue) {
          dp[i]++;
          new_layers.push_back(num * factor);
          factor++;
        }
      }
      layers = new_layers;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) ans = ans % 1000000007 * dp[i] % 1000000007;
    return ans;
  }
  void dfs(vector<int>& cur, int maxValue, int n) {
    if (cur.size() == n) {
      res++;
      res %= 1000000007;
      return;
    }
    int tail_num = cur[cur.size() - 1];
    int factor = 1;
    while (factor * tail_num <= maxValue) {
      cur.push_back(factor * tail_num);
      dfs(cur, maxValue, n);
      cur.pop_back();
      factor++;
    }
  }

 private:
  int res = 0;
};