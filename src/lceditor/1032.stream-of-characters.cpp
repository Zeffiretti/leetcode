/*
 * @lc app=leetcode id=1032 lang=cpp
 *
 * [1032] Stream of Characters
 */
#include "utils.h"
// @lc code=start
class StreamChecker {
  unordered_set<int> suffixHash, wordHash;
  deque<char> queryStream;
  int L = 0;
  int rollingHash(long &hash, long &p_pow, char c, int mod = 1e9 + 7) {
    p_pow = (p_pow * 31) % mod;
    return hash = (hash + (c - 'a' + 1) * p_pow) % mod;
  }
 public:
  StreamChecker(vector<string> &words) {
    for (auto &w : words) {
      long hash = 0, p_pow = 1;
      L = max(L, (int)size(w));
      for (int i = size(w) - 1; ~i; i--)
        suffixHash.insert(rollingHash(hash, p_pow, w[i]));
      wordHash.insert(hash);
    }
  }
  bool query(char c) {
    queryStream.push_front(c);
    if (size(queryStream) > L) queryStream.pop_back();
    for(int i = 0; i < size(queryStream); i++) {
      long hash = 0, p_pow = 1;
      for (int j = i; j < size(queryStream); j++)
        hash = rollingHash(hash, p_pow, queryStream[j]);
      if (wordHash.count(hash)) return true;
    }
    return false;
  }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
// @lc code=end

