#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int fillCups(vector<int>& amount) {
    fillCupsUtil(amount);
    return n;
  }
  void fillCupsUtil(vector<int>& amount) {
    sort(amount.begin(), amount.end());
    if (amount[0] == 0 && amount[1] == 0) {
      n += amount[2];
      return;
    }
    if (amount[0] == 0) {
      amount[1]--;
      amount[2]--;
      n++;
      fillCupsUtil(amount);
      return;
    }
    amount[0]--;
    amount[2]--;
    n++;
    fillCupsUtil(amount);
  }
  int n = 0;
};