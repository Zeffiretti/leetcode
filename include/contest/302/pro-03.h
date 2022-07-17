#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
    int n = nums[0].size();
    vector<int> res(queries.size());
    for (int i = 0; i < queries.size(); i++) {
      vector<pair<string, int>> temp;
      int k = queries[i][0];
      int trim = queries[i][1];
      for (int j = 0; j < nums.size(); j++) {
        // trim each number in nums to its rightmost trim digits
        // int num = stoi(nums[j].substr(n - trim));
        temp.push_back({nums[j].substr(n - trim), j});
      }
      sort(temp.begin(), temp.end());
      res[i] = temp[k - 1].second;
    }
    cout << endl;
    return res;
  }
};