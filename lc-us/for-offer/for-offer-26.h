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
  bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (A == nullptr || B == nullptr) {
      return false;
    }
    if (isSubStructure(A->left, B)) {
      return true;
    }
    if (isSubStructure(A->right, B)) {
      return true;
    }
    if (dfs(A, B)) {  //递归地，对于每一个节点，都需要进行一次判定
      return true;
    }
    return false;
  }
  bool dfs(TreeNode* A, TreeNode* B) {
    if (B == nullptr) return true;
    if (A == nullptr) return false;
    if (A->val != B->val) return false;
    return dfs(A->left, B->left) && dfs(A->right, B->right);
  }
};