/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
  ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode* mhead = new ListNode(head->val);
    ListNode* p = head->next;
    while (p != nullptr) {
      ListNode* q = mhead;
      if (p->val <= mhead->val) {
        ListNode* tmp = new ListNode(p->val);
        tmp->next = mhead;
        mhead = tmp;
        p = p->next;
        continue;
      }
      while (q->next != nullptr && q->next->val <= p->val) {
        q = q->next;
      }
      ListNode* tmp = q->next;
      q->next = new ListNode(p->val);
      q->next->next = tmp;
      p = p->next;
    }
    return mhead;
  }
};
// @lc code=end
