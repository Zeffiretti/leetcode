#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

#include <stdio.h>

class Solution {
 public:
  using ll = long long;
  int edgeScore(vector<int>& edges) {
    int n = edges.size();
    vector<vector<int>> directed_graph(n);
    for (int i = 0; i < n; i++) {
      directed_graph[edges[i]].push_back(i);
    }
    ll max_score = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
      ll score = 0;
      for (int j = 0; j < directed_graph[i].size(); j++) {
        score += directed_graph[i][j];
      }
      if (score > max_score) {
        max_score = score;
        res = i;
      }
    }
    return res;
  }
};