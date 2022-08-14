// @before-stub-for-debug-begin
#include <string>
#include <vector>

// #include "commoncppproblem25.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
 *     ListNode(int x, LPistNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 1) {
      return head;
    }
    ListNode* cur_head = head;
    ListNode* cur_tail = cur_head;
    int cnt = 1;
    while (cnt < k) {
      if (!cur_tail) {
        return head;
      }
      cur_tail = cur_tail->next;
      ++cnt;
    }
    if (!cur_tail) {
      return head;
    }
    ListNode* next_head = cur_tail->next;
    ListNode* pre = cur_head;
    ListNode* cur = pre->next;
    while (cur && cur != next_head) {
      ListNode* tmp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = tmp;
    }
    cur_head->next = reverseKGroup(next_head, k);
    return cur_tail;
  }
};
// @lc code=end
