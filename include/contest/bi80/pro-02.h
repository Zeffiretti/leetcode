#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
 public:
#define ll long long
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
    vector<int> res(spells.size(), 0);
    vector<vector<int>> spell_map(spells.size());
    // cout << "spell_map: " << endl;
    for (int i = 0; i < spells.size(); i++) {
      spell_map[i].push_back(spells[i]);
      spell_map[i].push_back(i);
    }
    // sort spell_map descendingly by spell_map[i][0]
    sort(spell_map.begin(), spell_map.end());
    reverse(spell_map.begin(), spell_map.end());
    // cout << "spell_map: ";
    sort(potions.begin(), potions.end());
    int i = 0, j = 0;
    for (; i < spell_map.size() && j < potions.size(); ++i) {
      ll sp = spell_map[i][0];
      ll po = potions[j];
      while (sp * po < success) {
        ++j;
        // cout << "j=" << j << endl;
        if (j >= potions.size())break;
        po = potions[j];
      }
      res[spell_map[i][1]] = potions.size() - j;
    }
    return res;
  }
};