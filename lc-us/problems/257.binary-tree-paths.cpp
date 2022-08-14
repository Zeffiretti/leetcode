/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if (!root) return res;
    dfs(res, "", root);
    return res;
  }
  void dfs(vector<string>& res, string cur, TreeNode* root) {
    if (!root) return;
    cur += to_string(root->val);
    if (!root->left && !root->right) {
      res.push_back(cur);
      return;
    }
    if (root->left) dfs(res, cur + "->", root->left);
    if (root->right) dfs(res, cur + "->", root->right);
  }
};
// @lc code=end
