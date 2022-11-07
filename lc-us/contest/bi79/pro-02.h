#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  string largestWordCount(vector<string>& messages, vector<string>& senders) {
    unordered_map<string, int> counts;
    for (int i = 0; i < messages.size(); ++i) {
      int count = 1;
      for (auto ch : messages[i]) {
        if (ch == ' ') count++;
      }
      counts[senders[i]] += count;
    }
    string res;
    int cnt = 0;
    for (auto& p : counts) {
      if (p.second > cnt) {
        res = p.first;
        cnt = p.second;
      } else if (p.second == cnt) {
        // lexicographically largest
        if (p.first > res) {
          res = p.first;
        }
      }
    }
    return res;
  }
};