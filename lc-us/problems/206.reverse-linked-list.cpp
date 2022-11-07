/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
  ListNode* reverseList(ListNode* head) {
    if (!head) return nullptr;
    if (!head->next) return head;
    ListNode* next = head->next;
    head->next = nullptr;
    ListNode* new_head = reverseList(next);
    next->next = head;
    return new_head;
  }
};
// @lc code=end
