#include <iostream>
#include <vector>
using namespace std;

void binary_search_tree() {
  int n;
  cin >> n;
  int pre;
  vector<int> dp(n + 1, 0);
  dp[0] = dp[1] = 1;
  //求1,2,...n能构成多少个不同的二叉搜索树
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[i] += dp[j - 1] * dp[i - j];
    }
  }
  cout << dp[n] << endl;
}