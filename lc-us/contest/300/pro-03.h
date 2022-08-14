#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

class Solution {
#define ll long long
 public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    //病毒在感染 delay 天后具有传染性
    //病毒在感染 forget 天后消失
    //初始有 1 个病毒，在具有传染性期间，每天每个病毒感染 1 个人，每个病毒感染的人都可以感染其他人
    //求在 n 天后，有多少人感染了病毒
    vector<ll> spreads(n + 1, 0);//第 i 天有多少病毒具有传染性
    vector<ll> infects(n + 1, 0);//第 i 天感染了多少人
    infects[1] = 1; //初始有 1 个病毒
    for (int i = delay + 1; i <= n; i++) {
      spreads[i] += infects[i - delay] % 1000000007;
      spreads[i] += spreads[i - 1] % 1000000007;
      if (i > forget) {
        spreads[i] -= infects[i - forget];
      }
      infects[i] = spreads[i];
    }
    ll res = 0;
    for (int i = 0; i < forget; ++i) {
      res += infects[n - i];
      cout << "infects[" << n - i << "]=" << infects[n - i] << endl;
    }
    //res+=spreads[n];
    return res % 1000000007;
  }
};