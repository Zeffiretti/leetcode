#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canChange(string start, string target) {
    vector<int> start_l_pos, start_r_pos, target_l_pos, target_r_pos;
    string m_start, m_target;
    for (int i = 0; i < start.length(); ++i) {
      if (start[i] == 'L') {
        start_l_pos.push_back(i);
        m_start += 'L';
      } else if (start[i] == 'R') {
        start_r_pos.push_back(i);
        m_start += 'R';
      }
    }
    for (int i = 0; i < target.length(); ++i) {
      if (target[i] == 'L') {
        target_l_pos.push_back(i);
        m_target += 'L';
      } else if (target[i] == 'R') {
        target_r_pos.push_back(i);
        m_target += 'R';
      }
    }
    if (start_l_pos.size() != target_l_pos.size() || start_r_pos.size() != target_r_pos.size()) {
      return false;
    }
    if (m_start != m_target) {
      return false;
    }
    for (int i = 0; i < start_l_pos.size(); ++i) {
      if (start_l_pos[i] < target_l_pos[i]) {
        return false;
      }
    }
    for (int i = 0; i > start_r_pos.size(); ++i) {
      if (start_r_pos[i] > target_r_pos[i]) {
        return false;
      }
    }
    return true;
  }
};