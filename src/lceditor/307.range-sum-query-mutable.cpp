/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */
#include "utils.h"
// @lc code=start

class SegmentTreeNode {
 public:
  int start, end;
  int sum;
  SegmentTreeNode* left;
  SegmentTreeNode* right;
  SegmentTreeNode(int start, int end, int sum) {
    this->start = start;
    this->end = end;
    this->sum = sum;
    this->left = this->right = nullptr;
  }
};
class NumArray {
 public:
  explicit NumArray(vector<int>& nums) { root_ = buildTree(nums, 0, nums.size() - 1); }

  void update(int index, int val) { update(root_, index, val); }

  int sumRange(int left, int right) {
    if (left > right) {
      return 0;
    }
    return sumRange(root_, left, right);
  }

 private:
  SegmentTreeNode* buildTree(vector<int>& nums, int start, int end) {
    if (start > end) {
      return nullptr;
    }
    if (start == end) {
      return new SegmentTreeNode(start, end, nums[start]);
    }
    int mid = start + (end - start) / 2;
    SegmentTreeNode* leftNode = buildTree(nums, start, mid);
    SegmentTreeNode* rightNode = buildTree(nums, mid + 1, end);
    SegmentTreeNode* node = new SegmentTreeNode(start, end, leftNode->sum + rightNode->sum);
    node->left = leftNode;
    node->right = rightNode;
    return node;
  }

  void update(SegmentTreeNode* root, int index, int val) {
    if (root->start == root->end) {  // leaf node
      root->sum = val;
      return;
    }
    int mid = root->start + (root->end - root->start) / 2;
    if (index <= mid) {
      update(root->left, index, val);
    } else {
      update(root->right, index, val);
    }
    root->sum = root->left->sum + root->right->sum;
  }

  int sumRange(SegmentTreeNode* root, int start, int end) {
    if (root->start == start && root->end == end) {
      return root->sum;
    }
    int mid = root->start + (root->end - root->start) / 2;
    if (end <= mid) {
      return sumRange(root->left, start, end);
    } else if (start >= mid + 1) {
      return sumRange(root->right, start, end);
    } else {
      return sumRange(root->left, start, mid) + sumRange(root->right, mid + 1, end);
    }
  }

  SegmentTreeNode* root_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
