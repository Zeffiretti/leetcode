/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator {
 public:
  BSTIterator(TreeNode* root) {
    while (root && root->left) {
      stk.push(root);
      root = root->left;
    }
    stk.push(root);
  }

  int next() {
    if (!hasNext()) return -1;
    TreeNode* node = stk.top();
    stk.pop();
    int res = node->val;
    if (node->right) {
      node = node->right;
      while (node && node->left) {
        stk.push(node);
        node = node->left;
      }
      stk.push(node);
    }
    return res;
  }

  bool hasNext() { return !stk.empty(); }

 private:
  stack<TreeNode*> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
