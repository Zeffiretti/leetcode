#ifndef JOBS_MEITUAN_MAXSUMBINARYTREE
#define JOBS_MEITUAN_MAXSUMBINARYTREE
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int dfs(std::vector<int>& tree, int idx) {
  if (idx >= tree.size()) {
    return 0;
  }
  return std::max(dfs(tree, idx * 2), dfs(tree, idx * 2 + 1)) + tree[idx];
}

void maxSumInBinaryTree() {
  int n;
  std::cin >> n;
  std::vector<int> nums(n + 1);
  for (int i = 1; i < n + 1; ++i) {
    std::cin >> nums[i];
  }
  int res = dfs(nums, 1);
  std::cout << res << std::endl;
}

#endif /* JOBS_MEITUAN_MAXSUMBINARYTREE */
