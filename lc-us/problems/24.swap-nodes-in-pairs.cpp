/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
class Solution {
 public:
  ListNode *swapPairs(ListNode *head) {
    if (!head) {
      return nullptr;
    }
    if (!head->next) {
      return head;
    }
    ListNode *next = head->next;
    ListNode *next2 = swapPairs(next->next);
    next->next = head;
    head->next = next2;
    return next;
  }
};
// @lc code=end

