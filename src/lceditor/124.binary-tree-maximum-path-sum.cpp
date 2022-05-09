/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
  int max_sum = INT_MIN;
  int maxPathSum(TreeNode *root) {
    max_sum = INT_MIN;
    unordered_map<TreeNode *, TreeNode *> sum;
    dfs(root, &sum);
    return max_sum;
  }
  void dfs(TreeNode *root,
           unordered_map<TreeNode *, TreeNode *> *max_sum_root) {
    if (!root) {
      return;
    }
    dfs(root->left, max_sum_root);
    dfs(root->right, max_sum_root);
    (*max_sum_root)[root] = new TreeNode(root->val);
    if ((*max_sum_root)[root->left] && (*max_sum_root)[root->right]) {
      (*max_sum_root)[root]->val +=
        max(max((*max_sum_root)[root->left]->val,
                (*max_sum_root)[root->right]->val),
            0);
    } else if ((*max_sum_root)[root->left]) {
      (*max_sum_root)[root]->val += max(0, (*max_sum_root)[root->left]->val);
    } else if ((*max_sum_root)[root->right]) {
      (*max_sum_root)[root]->val += max(0, (*max_sum_root)[root->right]->val);
    }
    int tmp_sum = root->val;
    if ((*max_sum_root)[root->left] &&
        (*max_sum_root)[root->left]->val > 0) {
      tmp_sum += (*max_sum_root)[root->left]->val;
    }
    if ((*max_sum_root)[root->right] &&
        (*max_sum_root)[root->right]->val > 0) {
      tmp_sum += (*max_sum_root)[root->right]->val;
    }
    if (tmp_sum > max_sum) {
      max_sum = tmp_sum;
    }
  }
};
// @lc code=end

