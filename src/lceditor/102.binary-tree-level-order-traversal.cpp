/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> trees;
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
      trees.push_back(tree);
      nodes = new_nodes;
    }
    return trees;
  }
};
// @lc code=end

