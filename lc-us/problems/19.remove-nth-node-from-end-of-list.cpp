/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* pNode = head;
    ListNode* qNode = pNode;
    for (int i = 0; i < n; i++) {
      qNode = qNode->next;
    }
    if (!qNode) {
      return head->next;
    }
    while (qNode->next) {
      pNode = pNode->next;
      qNode = qNode->next;
    }
    pNode->next = pNode->next->next;
    return head;
  }
};
// @lc code=end
