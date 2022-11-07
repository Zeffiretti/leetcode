/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 */
#include "utils.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  int sumNumbers(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->val;
    int res = 0;
    return dfs(root->left, root->val) + dfs(root->right, root->val);
  }
  int dfs(TreeNode* root, int val) {
    if (!root) return 0;
    val = val * 10 + root->val;
    if (!root->left && !root->right) {
      return val;
    }
    return dfs(root->left, val) + dfs(root->right, val);
  }
};
// @lc code=end
