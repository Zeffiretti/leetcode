/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
  ListNode* partition(ListNode* head, int x) {
    ListNode* small = new ListNode(0);
    ListNode* big = new ListNode(0);
    ListNode* curr_small = small;
    ListNode* curr_big = big;
    while (head) {
      if (head->val < x) {
        curr_small->next = head;
        curr_small = curr_small->next;
      } else {
        curr_big->next = head;
        curr_big = curr_big->next;
      }
      head = head->next;
    }
    curr_big->next = nullptr;
    curr_small->next = big->next;
    return small->next;
  }
};
// @lc code=end
