/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  using ll = long long;
  int pathSum(TreeNode* root, int targetSum) {
    if (!root) return 0;
    return pathSumFrom(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
  }
  int pathSumFrom(TreeNode* root, ll targetSum) {
    if (!root) return 0;
    return (root->val == targetSum ? 1 : 0) + pathSumFrom(root->left, targetSum - root->val) +
           pathSumFrom(root->right, targetSum - root->val);
  }
};
// @lc code=end
