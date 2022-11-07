#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "../../utils.h"
using namespace std;

#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    vector<vector<int>> res(m, vector<int>(n, -1));
    // right, down, left, up
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int i = 0, j = 0;
    int dir = 0;
    while (head) {
      res[i][j] = head->val;
      head = head->next;
      int new_i = i + dirs[dir].first;
      int new_j = j + dirs[dir].second;
      if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || res[new_i][new_j] != -1) {
        dir = (dir + 1) % 4;
      }
      i += dirs[dir].first;
      j += dirs[dir].second;
    }
    return res;
  }
};