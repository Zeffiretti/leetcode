/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */
#include "utils.h"
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
 public:
  Node *connect(Node *root) {
    if (!root) return nullptr;
    Node *cur = root;
    vector<Node *> cur_level;
    cur_level.push_back(cur);
    while (!cur_level.empty()) {
      vector<Node *> next_level;
      for (int i = 0; i < cur_level.size(); i++) {
        if (i < cur_level.size() - 1) {
          cur_level[i]->next = cur_level[i + 1];
        }
        if (cur_level[i]->left) next_level.push_back(cur_level[i]->left);
        if (cur_level[i]->right) next_level.push_back(cur_level[i]->right);
      }
      cur_level = next_level;
    }
    return root;
  }
};
// @lc code=end

