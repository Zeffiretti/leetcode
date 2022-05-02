#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
// 输出: [3,3,5,5,6,7]

vector<int> maxSlideWindow(vector<int> &nums, int k) {
  vector<int> ans;
  int n = nums.size();
  // int max_num = -INFINITY;
  // for (int i = 0; i < k; ++i) {
  //   max_num = max(max_num, nums[i]);
  // }
  // ans.push_back(max_num);
  // for (int i = k; i < n; ++i) {
  //   if (nums[i] > ans[ans.size() - 1]) {
  //     ans.push_back(nums[i]);
  //   }else{
  //   }
  // }

  // method 1:
  for (int i = 0; i < n - k + 1; ++i) {
    int max_num = -INFINITY;
    if (ans.size() != 0 && nums[i] > ans[ans.size() - 1]) {
      ans.push_back(nums[i]);
      break;
    }
    for (int j = i; j < i + k; ++j) {
      max_num = max(max_num, nums[j]);
    }
    ans.push_back(max_num);
  }
  return ans;
}



int main(int argc, char **argv) {
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  vector<int> ans = maxSlideWindow(nums, k);
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  return 0;
}