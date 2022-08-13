#ifndef JOBS_MEITUAN_MAXSUMBINARYTREE
#define JOBS_MEITUAN_MAXSUMBINARYTREE
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
int dfs(vector<int>& tree, int idx) {
  if (idx >= tree.size()) {
    return 0;
  }
  return max(dfs(tree, idx * 2), dfs(tree, idx * 2 + 1)) + tree[idx];
}

void maxSumInBinaryTree() {
  int n;
  cin >> n;
  vector<int> nums(n + 1);
  for (int i = 1; i < n + 1; ++i) {
    cin >> nums[i];
  }
  int res = dfs(nums, 1);
  cout << res << endl;
}

#endif /* JOBS_MEITUAN_MAXSUMBINARYTREE */
