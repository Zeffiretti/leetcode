#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
vector<int> max_values;
vector<int> used;

// struct projectcost {
//   int cost1;
//   int cost2;
//   int cost3;
// };

// 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
// 输出: [3,3,5,5,6,7]
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  int n = nums.size();
  if (n == 0) return {};
  vector<int> res;
  for (int i = 0; i < n - k + 1; i++) {
    int max_value = nums[i];
    for (int j = i; j < i + k; j++) {
      if (nums[j] > max_value) {
        max_value = nums[j];
      }
    }
    res.push_back(max_value);
  }
  return res;
}

//  Non-editable part
int main(int argc, char** argv) {
  int project_num;
  cin >> project_num;
  vector<int> human_resources(3);
  for (int i = 0; i < 3; i++) {
    cin >> human_resources[i];
  }
  vector<int> project_values(project_num);
  for (int i = 0; i < project_num; i++) {
    cin >> project_values[i];
  }
  vector<vector<int>> project_costs;
  for (int i = 0; i < project_num; i++) {
    vector<int> costs(3);
    for (int j = 0; j < 3; j++) {
      cin >> costs[j];
    }
    project_costs.push_back(costs);
  }
  // fill 'used' with 0
  used.resize(project_num, 0);

  return 0;
}