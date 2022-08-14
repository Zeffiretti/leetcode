#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
 public:
  int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks) {
    vector<int> free_space;
    for (int i = 0; i < capacity.size(); i++) {
      free_space.push_back(capacity[i] - rocks[i]);
    }
    // for (int i = 0; i < free_space.size(); i++) {
    //   cout << free_space[i] << " ";
    // }
    // cout << endl;
    sort(free_space.begin(), free_space.end());//ascending
    // for (int i = 0; i < free_space.size(); i++) {
    //   cout << free_space[i] << " ";
    // }
    // cout << endl;
    int bag = 0;
    int res = 0;
    while (bag < free_space.size() && free_space[bag] == 0) {
      bag++;
    }
    if (bag == free_space.size()) {
      return free_space.size();
    }
    while (additionalRocks > 0) {
      if (bag == free_space.size()) {
        return free_space.size();
      }
      additionalRocks -= free_space[bag];
      if (additionalRocks >= 0) {
        bag++;
      } else {
        break;
      }
    }
    return bag;
  }
};