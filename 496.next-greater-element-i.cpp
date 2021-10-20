/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */
#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    vector<int>ans;
    unordered_map<int, int>mp;
    stack<int>s;
    for (auto el : nums2) {
      while (!s.empty() && s.top() < el) {
        mp[s.top()] = el;
        s.pop();
      }
      s.push(el);
    }

    for (auto num : nums1) {
      ans.push_back(mp.count(num) ? mp[num] : -1);
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char **argv) {
  Solution sol;
  vector<int> nums1, nums2;
  nums1.resize(3);
  nums2.resize(4);
  nums1[0] = 4;
  nums1[1] = 1;
  nums1[2] = 2;
  nums2[0] = 1;
  nums2[1] = 3;
  nums2[2] = 4;
  nums2[3] = 2;
  vector<int> res = sol.nextGreaterElement(nums1, nums2);
  for (int i : res) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
