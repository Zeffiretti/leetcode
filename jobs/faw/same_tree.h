#ifndef JOBS_FAW_SAME_TREE
#define JOBS_FAW_SAME_TREE
struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param root1 TreeNode类
   * @param root2 TreeNode类
   * @return bool布尔型
   */
  bool isContains(TreeNode* root1, TreeNode* root2) {
    // write code here
    if (root1 == nullptr) {
      return false;
    }
    if (root2 == nullptr) {
      return true;
    }
    return isEqual(root1, root2) || isContains(root1->left, root2) || isContains(root1->right, root2);
  }

  bool isEqual(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr && t2 == nullptr) return true;
    if (t1 == nullptr || t2 == nullptr) return false;
    if (t1->val != t2->val) return false;
    return isEqual(t1->left, t2->left) && isEqual(t1->right, t2->right);
  }
};
#endif /* JOBS_FAW_SAME_TREE */
