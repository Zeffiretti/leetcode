/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */
#include "utils.h"
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
 public:
  Node *copyRandomList(Node *head) {
    if (!head) return nullptr;
    unordered_map<Node *, Node *> map;
    Node *cur = head;
    while (cur) {
      map[cur] = new Node(cur->val);
      cur = cur->next;
    }
    cur = head;
    while (cur) {
      map[cur]->next = map[cur->next];
      map[cur]->random = map[cur->random];
      cur = cur->next;
    }
    return map[head];
  }
};
// @lc code=end

