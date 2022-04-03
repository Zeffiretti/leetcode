/*
 * @lc app=leetcode id=1290 lang=cpp
 *
 * [1290] Convert Binary Number in a Linked List to Integer
 */

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
  int getDecimalValue(ListNode *head) {
    int res = 0;
    ListNode *iter = head;
    while (iter != NULL) {
      res <<= 1;
      res |= iter->val;
      iter = iter->next;
    }
    return res;
  }
};
// @lc code=end

