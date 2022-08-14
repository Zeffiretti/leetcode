#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums, vector<int>& numsDivide) {
    sort(nums.begin(), nums.end());
    if (nums[0] == 1) return 0;
    sort(numsDivide.begin(), numsDivide.end());
    vector<int> numsDivCopy;
    numsDivCopy.push_back(numsDivide[0]);
    for (int i = 1; i < numsDivide.size(); i++) {
      bool divided = false;
      for (int j = 0; j < numsDivCopy.size() && numsDivCopy[j] <= sqrt(numsDivide[i]); j++) {
        if (numsDivide[i] % numsDivCopy[j] == 0) {
          divided = true;
          break;
        }
      }
      if (!divided) {
        numsDivCopy.push_back(numsDivide[i]);
      }
    }
    int removed = 0;
    bool divided = true;
    for (int i = 0; i < nums.size(); ++i) {
      divided = true;
      if (nums[i] == removed) continue;
      for (int j = 0; j < numsDivCopy.size(); ++j) {
        if (numsDivCopy[j] % nums[i] != 0) {
          divided = false;
          removed = nums[i];
          break;
        }
      }
      if (divided) {
        return i;
      }
    }
    return -1;
  }
};