/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
  bool hasCycle(ListNode* head) {
    unordered_set<ListNode*> visited;
    while (head) {
      if (visited.find(head) != visited.end()) {
        return true;
      }
      visited.insert(head);
      head = head->next;
    }
    return false;
  }
};
// @lc code=end
