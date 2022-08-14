#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  string decodeMessage(string key, string message) {
    vector<char> keys(26, ' ');
    int j = 0;
    for (int i = 0; i < key.size(); i++) {
      if (key[i] >= 'a' && key[i] <= 'z' && keys[key[i] - 'a'] == ' ') {
        keys[key[i] - 'a'] = 'a' + j;
        ++j;
      }
    }
    string res;
    for (int i = 0; i < message.size(); i++) {
      if (message[i] >= 'a' && message[i] <= 'z') {
        res += keys[message[i] - 'a'];
      } else {
        res += message[i];
      }
    }
    return res;
  }
};