#include <vector>

class Solution {
 public:
  bool verifyPostorder(const std::vector<int>& postorder) {
    return verifyPostorder(postorder, 0, postorder.size() - 1);
  }
  bool verifyPostorder(const std::vector<int>& postorder, int start, int end) {
    if (start >= end) return true;
    int i = start;
    while (postorder[i] < postorder[end]) ++i;
    int j = i;
    while (postorder[j] > postorder[end]) ++j;
    if (j != end) return false;
    return verifyPostorder(postorder, start, i - 1) && verifyPostorder(postorder, i, end - 1);
  }
};