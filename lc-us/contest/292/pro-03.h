#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int countTexts(string pressedKeys) {
    vector<int> keys(9, 3);
    keys['7' - '1'] = 4;
    keys['9' - '1'] = 4;
    // print(keys);
    cout << endl;
    vector<int> dp(pressedKeys.size() + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    int cnt = 1;
    for (int i = 1; i < pressedKeys.size(); i++) {
      if (pressedKeys[i] != pressedKeys[i - 1]) {
        cnt = 1;
        dp[i + 1] = dp[i];
      } else {
        cnt++;
        int key = min(cnt, keys[pressedKeys[i] - '1']);
        for (int j = 0; j < key; ++j) {
          dp[i + 1] += dp[i - j];
          dp[i + 1] %= 1000000007;
        }
      }
    }
    cout << endl;
    return dp[pressedKeys.size()] % (1000000007);
  }
};