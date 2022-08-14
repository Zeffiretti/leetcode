/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */
#include "utils.h"
// @lc code=start
class Trie {
 public:
  Trie() {
    root = new TrieNode();
  }

  void insert(string word) {
    TrieNode *cur = root;
    for (int i = 0; i < word.size(); ++i) {
      if (cur -> children[word[i] - 'a'] == nullptr) {
        cur -> children[word[i] - 'a'] = new TrieNode();
      }
      cur = cur -> children[word[i] - 'a'];
    }
    cur -> is_word = true;
  }

  bool search(string word) {
    TrieNode *cur = root;
    for (int i = 0; i < word.size(); ++i) {
      if (cur -> children[word[i] - 'a'] == nullptr) {
        return false;
      }
      cur = cur -> children[word[i] - 'a'];
    }
    return cur -> is_word;
  }

  bool startsWith(string prefix) {
    TrieNode *cur = root;
    for (int i = 0; i < prefix.size(); ++i) {
      if (cur -> children[prefix[i] - 'a'] == nullptr) {
        return false;
      }
      cur = cur -> children[prefix[i] - 'a'];
    }
    return true;
  }
 private:
  struct TrieNode {
    TrieNode *children[26];
    bool is_word;
    TrieNode() : is_word(false) {
      for (int i = 0; i < 26; ++i) {
        children[i] = nullptr;
      }
    }
  };
  TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

