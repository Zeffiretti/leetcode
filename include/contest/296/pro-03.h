#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

struct node {
  int val;
  node *next;
  node(int v): val(v), next(NULL) {}
};

class Solution {
 public:
  vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations) {
    map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
      m[nums[i]] = i;
    }
    for (int i = 0; i < operations.size(); ++i) {
      int index = m[operations[i][0]];
      nums[index] = operations[i][1];
      m[operations[i][1]] = index;
    }
    return nums;
  }
};