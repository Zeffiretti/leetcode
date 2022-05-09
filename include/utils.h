#ifndef __UTILS_H_
#define __UTILS_H_
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <string>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node {
 public:
  int val;
  Node *left;
  Node *right;
  Node *next;
  Node *random;

  Node() :
    val(0),
    left(NULL),
    right(NULL),
    next(NULL),
    random(NULL) {}

  Node(int _val) :
    val(_val),
    left(NULL),
    right(NULL),
    next(NULL),
    random(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
    : val(_val),
      left(_left),
      right(_right),
      next(_next),
      random(NULL) {}
};

#endif