#include <algorithm>
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
  int totalStrength(vector<int>& strength) {
    int res = 0;
    for (int i = 1; i <= strength.size(); ++i) {
      cout << "i: " << i << endl;
      list<int> list_;
      unordered_map<int, list<int>::iterator> map_;
      int sum = 0;
      for (int j = 0; j < i; ++j) {
        sum += strength[j];
        int val = strength[j];
        // insert val into l, ascending order
        if (list_.empty()) {
          list_.push_back(val);
          map_[j] = list_.begin();
        } else {
          auto it = list_.begin();
          while (it != list_.end() && *it < val) {
            ++it;
          }
          list_.insert(it, val);
          map_[j] = it;
        }
      }
      res += *list_.begin() * sum % 1000000007;
      for (int j = i; j < strength.size(); ++j) {
        cout << "j: " << j << endl;
        sum = sum - strength[j - i] + strength[j];
        int val = strength[j];
        auto it = map_[j - i];
        list_.erase(it);
        if (list_.empty()) {
          list_.push_back(val);
          map_[j] = list_.begin();
        } else {
          it = list_.begin();
          while (it != list_.end() && *it < val) {
            ++it;
          }
          list_.insert(it, val);
          map_[j] = it;
        }
        res += *list_.begin() * sum % 1000000007;
        cout << "res: " << res << endl;
      }
    }
    return res;
  }
};