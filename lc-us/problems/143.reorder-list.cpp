/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
  void reorderList(ListNode* head) {
    if (head == nullptr) return;
    if (head->next == nullptr) return;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode* second = slow->next;
    slow->next = nullptr;
    ListNode* first = head;
    queue<ListNode*> q;  // the first half
    stack<ListNode*> s;  // the second half
    while (first) {
      q.push(first);
      first = first->next;
    }
    while (second) {
      s.push(second);
      second = second->next;
    }
    ListNode* dummy = new ListNode(0);
    while (!q.empty() && !s.empty()) {
      ListNode* first = q.front();
      q.pop();
      ListNode* second = s.top();
      s.pop();
      first->next = second;
      dummy->next = first;
      dummy = dummy->next->next;
    }
    if (!q.empty()) {
      dummy->next = q.front();
    }
    if (!s.empty()) {
      dummy->next = s.top();
    }
    // return head;
  }
};
// @lc code=end
