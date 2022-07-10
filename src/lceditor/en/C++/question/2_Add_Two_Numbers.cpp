// @algorithm @lc id=2 lang=cpp
// @title add-two-numbers


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([2,4,3],[5,6,4])=[7,0,8]
// @test([0],[0])=[0]
// @test([9,9,9,9,9,9,9],[9,9,9,9])=[8,9,9,9,0,0,0,1]
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    int carry = 0;
    while (l1 || l2) {
      int sum = carry;
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }
      carry = sum / 10;
      p->next = new ListNode(sum % 10);
      p = p->next;
    }
    if (carry) {
      p->next = new ListNode(carry);
    }
    return head->next;
  }
};