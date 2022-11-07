#include <iostream>
using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;

  Node() {}

  Node(int _val) {
    val = _val;
    left = NULL;
    right = NULL;
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
    if (root == NULL) return NULL;
    Node* head = NULL;
    Node* tail = NULL;
    dfs(root, &head, &tail);
    head->left = tail;
    tail->right = head;
    return head;
  }
  void dfs(Node* root, Node** head, Node** tail) {
    if (root == NULL) return;
    dfs(root->left, head, tail);
    if (*head == NULL) {
      *head = root;
    } else {
      root->left = *tail;
      (*tail)->right = root;
    }
    *tail = root;
    dfs(root->right, head, tail);
  }
};