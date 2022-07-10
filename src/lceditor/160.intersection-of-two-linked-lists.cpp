/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode *> set;
    ListNode *cur = headA;
    while (cur) {
      set.insert(cur);
      cur = cur->next;
    }
    cur = headB;
    while (cur) {
      if (set.count(cur)) return cur;
      cur = cur->next;
    }
    return nullptr;
  }
};
// @lc code=end

