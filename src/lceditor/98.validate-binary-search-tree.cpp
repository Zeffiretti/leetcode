/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
  bool isValidBST(TreeNode *root) {
    return isValidBST(root, nullptr, nullptr);
  }
  bool isValidBST(TreeNode *root, TreeNode *left, TreeNode *right) {
    if (!root) return true;
    if (left && root->val <= left->val) return false;
    if (right && root->val >= right->val) return false;
    return isValidBST(root->left, left, root) && isValidBST(root->right, root, right);
  }
};
// @lc code=end

