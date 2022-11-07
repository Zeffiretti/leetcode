/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
  ListNode* rotateRight(ListNode* head, int k) {
    int cnt = 0;
    ListNode* tail = head;
    while (tail && tail->next) {
      tail = tail->next;
      cnt++;
    }
    if (cnt == 0) {
      return head;
    }
    tail->next = head;
    cnt++;
    k = k % cnt;
    for (int i = 0; i <= cnt - k - 1; i++) {
      tail = tail->next;
    }
    head = tail->next;
    tail->next = nullptr;
    return head;
  }
};
// @lc code=end
