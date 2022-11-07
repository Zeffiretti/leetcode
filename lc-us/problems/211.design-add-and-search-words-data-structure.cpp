/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */
#include "utils.h"
// @lc code=start
struct TrieNode {
  TrieNode* children[26];
  bool isWord;
  TrieNode() : isWord(false) {
    for (int i = 0; i < 26; ++i) {
      children[i] = nullptr;
    }
  }
};
class WordDictionary {
 public:
  WordDictionary() { root = new TrieNode(); }
  void addWord(string word) {
    TrieNode* cur = root;
    for (char c : word) {
      if (cur->children[c - 'a'] == nullptr) {
        cur->children[c - 'a'] = new TrieNode();
      }
      cur = cur->children[c - 'a'];
    }
    cur->isWord = true;
  }
  bool search(string word) { return search(word, root); }

 private:
  TrieNode* root;
  bool search(string word, TrieNode* cur) {
    if (word.empty()) {
      return cur->isWord;
    }
    if (word[0] == '.') {
      for (int i = 0; i < 26; ++i) {
        if (cur->children[i] && search(word.substr(1), cur->children[i])) {
          return true;
        }
      }
    } else {
      if (cur->children[word[0] - 'a'] && search(word.substr(1), cur->children[word[0] - 'a'])) {
        return true;
      }
    }
    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
