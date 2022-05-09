/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */
#include "utils.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head) return nullptr;
    if (!head->next) return new TreeNode(head->val);
    if (!head->next->next) {
      TreeNode *root = new TreeNode(head->val);
      root->right = new TreeNode(head->next->val);
      return root;
    }
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
      dummy = dummy->next;
      slow = slow->next;
      fast = fast->next->next;
    }
    TreeNode *root = new TreeNode(slow->val);
    ListNode *right = slow->next;
    dummy->next = nullptr;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(right);
    return root;
  }
};
// @lc code=end

