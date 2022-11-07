/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
  vector<TreeNode*> generateTrees(int n) {
    if (n == 0) {
      return {};
    }
    return generateTrees(1, n);
  }
  vector<TreeNode*> generateTrees(int start, int end) {
    vector<TreeNode*> res;
    if (start > end) {
      res.push_back(nullptr);
      return res;
    }
    for (int i = start; i <= end; i++) {
      vector<TreeNode*> left_trees = generateTrees(start, i - 1);
      vector<TreeNode*> right_trees = generateTrees(i + 1, end);
      for (auto left : left_trees) {
        for (auto right : right_trees) {
          TreeNode* root = new TreeNode(i);
          root->left = left;
          root->right = right;
          res.push_back(root);
        }
      }
    }
    return res;
  }
};
// @lc code=end
