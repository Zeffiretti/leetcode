/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
  int kthSmallest(TreeNode* root, int k) {
    if (!root) return 0;
    int left = countNodes(root->left);
    if (left + 1 == k) return root->val;
    if (left + 1 > k) return kthSmallest(root->left, k);
    return kthSmallest(root->right, k - left - 1);
  }
  int countNodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
// @lc code=end
