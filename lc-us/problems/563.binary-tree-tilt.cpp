/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
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
  int tiltSum = 0;
  int findTilt(TreeNode* root) {
    DFS(root);
    return tiltSum;
  }
  int DFS(TreeNode* root) {
    if (!root) return 0;
    int leftSum = DFS(root->left);          // sum of left subtree
    int rightSum = DFS(root->right);        // sum of right subtree
    tiltSum += abs(leftSum - rightSum);     // add tilt of current node to overall tiltSum
    return leftSum + rightSum + root->val;  // returns sum of subtree starting at 'root'
  }
};
// @lc code=end
