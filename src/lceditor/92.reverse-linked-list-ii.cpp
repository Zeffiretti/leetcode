/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy;
    ListNode *cur = head;
    for (int i = 0; i < left - 1; ++i) {
      prev = cur;
      cur = cur->next;
    }
    ListNode *start = cur;
    ListNode *end = cur->next;
    for (int i = left; i < right; ++i) {
      ListNode *tmp = end->next;
      end->next = cur;
      cur = end;
      end = tmp;
    }
    prev->next = cur;
    start->next = end;
    return dummy->next;
  }
};
// @lc code=end

