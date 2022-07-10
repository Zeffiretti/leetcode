/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *dummy = new ListNode(-1, head), *prev = dummy;
    for (; head; head = head -> next) {
      if (head -> val != val)
        prev = head;
      else
        prev -> next = head -> next;
    }
    return dummy -> next;
  }
};
// @lc code=end

