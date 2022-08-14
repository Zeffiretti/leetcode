/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    int depth = depthOfTree(root);
    vector<vector<int>> trees(depth);
    if (!root) return trees;
    vector<TreeNode *> nodes;
    nodes.push_back(root);
    while (!nodes.empty()) {
      vector<TreeNode *> new_nodes;
      vector<int> tree;
      for (int i = 0; i < nodes.size(); ++i) {
        tree.push_back(nodes[i]->val);
        if (nodes[i]->left) {
          new_nodes.push_back(nodes[i]->left);
        }
        if (nodes[i]->right) {
          new_nodes.push_back(nodes[i]->right);
        }
      }
      trees[--depth] = tree;
      nodes = new_nodes;
    }
    return trees;
  }
 private:
  int depthOfTree(TreeNode *root) {
    if (!root) return 0;
    return max(depthOfTree(root->left), depthOfTree(root->right)) + 1;
  }
};
// @lc code=end

