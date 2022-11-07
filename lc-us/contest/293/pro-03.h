#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int largestCombination(vector<int>& candidates) {
    if (candidates.size() == 1) return 1;
    vector<pair<int, int>> special;
    special.push_back({candidates[0], 1});
    for (int i = 1; i < candidates.size(); ++i) {
      bool found = false;
      for (int j = 0; j < special.size(); ++j) {
        if ((candidates[i] & special[j].first) > 0) {
          special[j].first &= candidates[i];
          special[j].second++;
          found = true;
        }
      }
      if (!found) {
        special.push_back({candidates[i], 1});
      }
    }
    int res = special[0].second;
    for (int i = 1; i < special.size(); ++i) {
      res = max(res, special[i].second);
    }
    return res;
  }
};

//[84,40,66,44,91,90,1,14,73,51,47,35,18,46,18,65,55,18,16,45,43,58,90,92,91,43,44,76,85,72,24,89,60,94,81,90,86,79,84,41,41,28,44]
//[40,35,37,9,32,1,84,48,85,75,94,36,58,85,8,6,91,3,9,69,27,41,99,14,89,18,48,1,42,65,81,46,60,45,64,56,72,40,9,58,23,82,41,27,79,52]