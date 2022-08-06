#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  typedef long long ll;
  ll countBadPairs(vector<int>& nums) {
    ll result = 0;
    map<ll, ll> m;
    for (int i = 0; i < nums.size(); ++i) {
      ll y = nums[i] - i;
      if (m.find(y) == m.end()) {
        m[y] = 1;
      } else {
        m[y]++;
      }
    }
    for (int i = 0; i < nums.size(); ++i) {
      ll y = nums[i] - i;
      result += nums.size() - m[y];
    }
    return result / 2;
  }
};