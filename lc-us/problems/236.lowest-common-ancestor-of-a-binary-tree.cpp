/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */
#include "utils.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    stack<TreeNode*> p_path;
    stack<TreeNode*> q_path;
    dfs_search(root, p, p_path);
    dfs_search(root, q, q_path);
    TreeNode* lca = nullptr;
    while (!p_path.empty() && !q_path.empty()) {
      TreeNode* p_node = p_path.top();
      TreeNode* q_node = q_path.top();
      if (p_node == q_node) {
        lca = p_node;
      } else {
        break;
      }
      p_path.pop();
      q_path.pop();
    }
    return lca;
  }

  bool dfs_search(TreeNode* root, TreeNode* p, stack<TreeNode*>& path) {
    if (!root) return false;
    if (root == p) {
      path.push(root);
      return true;
    }
    bool found = dfs_search(root->left, p, path);
    if (found) {
      path.push(root);
      return true;
    }
    found = dfs_search(root->right, p, path);
    if (found) {
      path.push(root);
      return true;
    }
    return false;
  }
};
// @lc code=end
