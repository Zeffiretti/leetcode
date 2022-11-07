#include <unordered_map>
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
  int cnt = 0;
  void count_dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>* sum, unordered_map<TreeNode*, TreeNode*>* count) {
    if (root == nullptr) {
      return;
    }
    if ((*count)[root]->val == 0) {
      cnt++;
    } else if ((*sum)[root]->val / (*count)[root]->val == root->val) {
      cnt++;
    }
    count_dfs(root->left, sum, count);
    count_dfs(root->right, sum, count);
  }
  int averageOfSubtree(TreeNode* root) {
    unordered_map<TreeNode*, TreeNode*> sum;
    unordered_map<TreeNode*, TreeNode*> count;
    sum[root] = root;
    count[root] = root;
    dfs(root, &sum, &count);
    count_dfs(root, &sum, &count);
    return cnt;
  }
  void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>* sum, unordered_map<TreeNode*, TreeNode*>* count) {
    if (root == nullptr) {
      return;
    }
    dfs(root->left, sum, count);
    dfs(root->right, sum, count);
    (*count)[root] = new TreeNode(1);
    (*sum)[root] = new TreeNode(root->val);
    if (root->left != nullptr) {
      (*sum)[root]->val += (*sum)[root->left]->val;
      (*count)[root]->val += (*count)[root->left]->val;
    }
    if (root->right != nullptr) {
      (*sum)[root]->val += (*sum)[root->right]->val;
      (*count)[root]->val += (*count)[root->right]->val;
    }
  }
};