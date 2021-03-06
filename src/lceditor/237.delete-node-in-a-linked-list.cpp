/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */
#include "utils.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  void deleteNode(ListNode* node) {
    if (!node) return;
    if (!node->next) {
      delete node;
      return;
    }
    ListNode* next = node->next;
    node->val = next->val;
    node->next = next->next;
    delete next;
  }
};
// @lc code=end
