/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    vector<TreeNode*> level;
    level.push_back(root);
    bool is_reverse = false;
    while (!level.empty()) {
      vector<int> cur;
      vector<TreeNode*> next;
      for (int i = 0; i != level.size(); i++) {
        cur.push_back(level[i]->val);
        if (level[i]->left) next.push_back(level[i]->left);
        if (level[i]->right) next.push_back(level[i]->right);
      }
      if (is_reverse) reverse(cur.begin(), cur.end());
      is_reverse = !is_reverse;
      res.push_back(cur);
      level = next;
    }
    return res;
  }
};
// @lc code=end
