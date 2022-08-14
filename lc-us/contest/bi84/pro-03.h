#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  using ll = long long;
  ll taskSchedulerII(const vector<int>& tasks, int space) {
    ll days = 1;
    if (tasks.size() == 0) {
      return 0;
    }
    if (tasks.size() == 1) {
      return 1;
    }
    map<ll, ll> finished_day;
    for (int i = 0; i < tasks.size(); ++i) {
      if (finished_day.find(tasks[i]) == finished_day.end()) {  // encounter new task
        days++;
        finished_day[tasks[i]] = days;
      } else {
        days = max(days + 1, finished_day[tasks[i]] + space + 1);
        finished_day[tasks[i]] = days;
      }
    }
    return days;
  }
};