/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) {
      return res;
    }
    postorder(root, res);
    return res;
  }

  void postorder(TreeNode* root, vector<int>& res) {
    if (root == nullptr) {
      return;
    }
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
  }
};
// @lc code=end
