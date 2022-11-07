/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
  bool isBalanced(TreeNode* root) {
    if (!root) return true;
    int left = getDepth(root->left);
    int right = getDepth(root->right);
    if (abs(left - right) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
  }
  int getDepth(TreeNode* root) {
    if (!root) return 0;
    int left = getDepth(root->left);
    int right = getDepth(root->right);
    return max(left, right) + 1;
  }
};
// @lc code=end
