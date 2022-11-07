#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxConsecutive(int bottom, int top, vector<int>& special) {
    sort(special.begin(), special.end());
    if (special.empty()) {
      return top - bottom + 1;
    }
    if (special.size() == top - bottom + 1) {
      return 0;
    }
    int max_consecutive = special[0] - bottom;
    for (int i = 1; i < special.size(); ++i) {
      max_consecutive = max(max_consecutive, special[i] - special[i - 1]);
    }
    max_consecutive = max(max_consecutive, top - special.back());
    return max_consecutive;
  }
};