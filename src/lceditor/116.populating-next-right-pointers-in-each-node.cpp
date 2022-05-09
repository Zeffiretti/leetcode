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
    vector<Node *> nodes;
    nodes.push_back(root);
    while (!nodes.empty()) {
      int size = nodes.size();
      vector<Node *> next_nodes;
      for (int i = 0; i < size - 1; ++i) {
        // cout << nodes[i]->val << " -> ";
        nodes[i]->next = nodes[i + 1];
        if (nodes[i]->left)
          next_nodes.push_back(nodes[i]->left);
        if (nodes[i]->right)
          next_nodes.push_back(nodes[i]->right);
      }
      // cout << nodes[size - 1]->val << endl;
      nodes[size - 1]->next = nullptr;
      if (nodes[size - 1]->left)
        next_nodes.push_back(nodes[size - 1]->left);
      if (nodes[size - 1]->right)
        next_nodes.push_back(nodes[size - 1]->right);
      nodes = next_nodes;
    }
    return root;
  }
};
// @lc code=end

