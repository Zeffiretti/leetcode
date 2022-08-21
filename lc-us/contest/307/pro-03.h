#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int amountOfTime(TreeNode* root, int start) {
    if (root == nullptr) {
      return 0;
    }
    deque<TreeNode*> path;
    path_to_val(root, start, &path);
  }

  void path_to_val(TreeNode* root, int val, deque<TreeNode*>* path) {
    if (root == nullptr) {
      return;
    }
    path->push_back(root);
    if (root->val == val) {
      return;
    }
    path_to_val(root->left, val, path);
    if (path->back()->val == val) {
      return;
    }
    path_to_val(root->right, val, path);
  }

  int dfs(TreeNode* root, int val, int* res) {
    if (root == nullptr) {
      return 0;
    }
    if (root->val == val) {
      return 1;
    }
    int left = dfs(root->left, val, res);
    int right = dfs(root->right, val, res);
    if (left + right > 0) {
      *res += 1;
    }
    return left + right;
  }

 private:
  int m_max_day = 0;
};