/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
  void rec(TreeNode *root, int low, int high) {
    if (!root) return;
    if (root->val <= high && root->val >= low) res += root->val;
    rec(root->left, low, high);
    rec(root->right, low, high);
  }

  int rangeSumBST(TreeNode *root, int low, int high) {
    rec(root, low, high);
    return res;
  }

 private:
  int res = 0;
};
// @lc code=end

int main(int argc, char **arhv) {
  std::cout << "good" << std::endl;
  return 0;
}