#include <iostream>

class Node {
 public:
  int val;
  Node* left;
  Node* right;

  Node() = default;
  Node(int _val) {
    val = _val;
    left = nullptr;
    right = nullptr;
  }

  Node(int _val, Node* _left, Node* _right) {
    val = _val;
    left = _left;
    right = _right;
  }
};

class Solution {
 public:
  Node* treeToDoublyList(Node* root) {
    if (root == nullptr) return nullptr;
    Node* head = nullptr;
    Node* tail = nullptr;
    dfs(root, &head, &tail);
    head->left = tail;
    tail->right = head;
    return head;
  }
  void dfs(Node* root, Node** head, Node** tail) {
    if (root == nullptr) return;
    dfs(root->left, head, tail);
    if (*head == nullptr) {
      *head = root;
    } else {
      root->left = *tail;
      (*tail)->right = root;
    }
    *tail = root;
    dfs(root->right, head, tail);
  }
};