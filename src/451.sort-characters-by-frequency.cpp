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
    unordered_map<char, int> freq;
    vector<string> bucket(s.size() + 1, "");
    string res;

    //count frequency of each character
    for (char c : s) freq[c]++;
    //put character into frequency bucket
    for (auto &it : freq) {
      int n = it.second;
      char c = it.first;
      bucket[n].append(n, c);
    }
    //form descending sorted string
    for (int i = s.size(); i > 0; i--) {
      if (!bucket[i].empty())
        res.append(bucket[i]);
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char **argv) {
  Solution solution;
  string input = "eerasuifjkwretdmwkerjiiooosdwelkdtgerdfgklfffffffklll";
  cout << solution.frequencySort(input) << endl;
}