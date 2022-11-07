#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
    sort(tiles.begin(), tiles.end());
    int res = tiles[0][1] - tiles[0][0] + 1;
    if (res >= carpetLen) {
      return carpetLen;
    }
    int idx = 1;
    while (tiles[0][0] + carpetLen > tiles[idx][1]) {
      res += tiles[idx][1] - tiles[idx][0] + 1;
      idx++;
    }
    if (tiles[0][0] + carpetLen > tiles[idx][0]) {
      res += tiles[0][0] + carpetLen - tiles[idx][0] + 1;
    }
    if (res >= carpetLen) {
      return carpetLen;
    }
    int tmp_len = res;
    for (int i = 1; i < tiles.size(); ++i) {
      tmp_len -= tiles[i - 1][1] - tiles[i - 1][0] + 1;
      tmp_len -= tiles[i][1] - tiles[i][0] + 1;
    }
  }
};