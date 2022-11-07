#include <vector>
using namespace std;

class Solution {
 public:
  bool verifyPostorder(vector<int>& postorder) { return verifyPostorder(postorder, 0, postorder.size() - 1); }
  bool verifyPostorder(vector<int>& postorder, int start, int end) {
    if (start >= end) return true;
    int i = start;
    while (postorder[i] < postorder[end]) ++i;
    int j = i;
    while (postorder[j] > postorder[end]) ++j;
    if (j != end) return false;
    return verifyPostorder(postorder, start, i - 1) && verifyPostorder(postorder, i, end - 1);
  }
};