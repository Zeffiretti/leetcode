#ifndef INCLUDE_UTILS_H
#define INCLUDE_UTILS_H

#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifndef INT_MIN
#  define INT_MIN INT32_MIN
#endif

#ifndef INT_MAX
#  define INT_MAX INT32_MAX
#endif

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left_, TreeNode* right_) : val(x), left(left_), right(right_) {}
};

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;
  Node* random;
  vector<Node*> neighbors;

  Node() : val(0), left(NULL), right(NULL), next(NULL), random(NULL) { neighbors = vector<Node*>(); }

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL), random(NULL) { neighbors = vector<Node*>(); }

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next), random(NULL) {
    neighbors = vector<Node*>();
  }

  Node(int _val, Node* _left, Node* _right, Node* _next, vector<Node*> _neighbors)
      : val(_val), left(_left), right(_right), next(_next), random(NULL) {
    neighbors = _neighbors;
  }

  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

#endif