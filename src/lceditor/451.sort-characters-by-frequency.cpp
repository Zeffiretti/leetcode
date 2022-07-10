/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */
#include <string>
#include <map>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
 public:
  string frequencySort(string s) {
    vector<vector<int>> freqs(256, vector<int>(2, 0));
    for (char c : s) {
      freqs[c][0]++;
      freqs[c][1] = c;
    }
    sort(freqs.begin(), freqs.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[0] > b[0];
    });
    string ans;
    for (auto &freq : freqs) {
      for (int i = 0; i < freq[0]; i++) {
        ans += freq[1];
      }
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char **argv) {
  Solution solution;
  string input = "eerasuifjkwretdmwkerjiiooosdwelkdtgerdfgklfffffffklll";
  cout << solution.frequencySort(input) << endl;
}