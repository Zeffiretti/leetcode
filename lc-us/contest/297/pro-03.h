#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int distributeCookies(vector<int>& cookies, int k) {
    vector<vector<vector<int>>> distributes(k);
    vector<vector<int>> used(k, vector<int>(cookies.size(), 0));
    dfs_distribute(distributes, cookies, used, k);
    int res = INT_MAX;
    for (int i = 0; i < distributes[0].size(); i++) {  // 一共 distributes[0].size() 种分配方法
      int max_cookie = INT_MIN;
      for (int j = 0; j < distributes.size(); j++) {  // 一共 distributes.size() 个人
        int cookie = 0;
        for (int k = 0; k < distributes[j][i].size(); ++k) {
          cookie += distributes[j][i][k];
        }
        max_cookie = max(max_cookie, cookie);
      }
      res = min(res, max_cookie);
    }
    return res;
  }
  void dfs_distribute(vector<vector<vector<int>>>& all_dists, vector<int>& cookies, vector<vector<int>>& used, int n) {
    if (n == 1) {
      vector<vector<int>> dist;
      for (int i = 0; i < used.size(); ++i) {
        vector<int> pre_used = used[i];
        vector<int> dist_i;
        for (int j = 0; j < cookies.size(); ++j) {
          if (pre_used[j] == 1) {
            dist_i.push_back(cookies[j]);
          }
        }
        dist.push_back(dist_i);
      }
      all_dists.push_back(dist);
      return;
    }
    for (int i = 0; i < used.size(); ++i) {
      vector<int> pre_used = used[i];
      int pre_used_count = 0;
      for (int j = 0; j < cookies.size(); ++j) {
        if (pre_used[j] == 1) {
          pre_used_count++;
        }
      }
      for (int i = 1; i + pre_used_count + n <= cookies.size(); i++) {
        vector<vector<int>> picked;
        vector<int> picked_cookies;
        dfs_pick(picked, picked_cookies, cookies, pre_used, i);
        all_dists.push_back(picked);
        used[i] = pre_used;
        dfs_distribute(all_dists, cookies, used, n - 1);
      }
    }
  }
  void dfs_pick(vector<vector<int>>& res, vector<int>& cur, vector<int>& cookies, vector<int>& used, int n) {
    if (cur.size() == n) {
      res.push_back(cur);
      return;
    }
    for (int i = 0; i < cookies.size(); ++i) {
      if (used[i]) continue;
      used[i] = 1;
      cur.push_back(cookies[i]);
      dfs_pick(res, cur, cookies, used, n);
      used[i] = 0;
      cur.pop_back();
    }
  }
};