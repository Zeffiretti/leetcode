#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
#define ll long long
  long long countSubarrays(vector<int>& nums, long long k) {
    int slow = -1, fast = 0;
    int res = 0;
    long long sum = 0;
    while (fast < nums.size()) {
      sum += nums[fast];
      ll score = sum * (fast - slow);
      while (score >= k && slow < fast) {
        ++slow;
        sum -= nums[slow];
        score = sum * (fast - slow);
      }
      if (score < k) {
        cout << "left: " << slow << " right: " << fast << " score: " << score << endl;
        res++;
      }
      ++fast;
    }
    return res;
  }
};