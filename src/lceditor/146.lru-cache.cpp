/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */
#include "utils.h"
// @lc code=start
class LRUCache {
 public:
  int cap;
  list<pair<int, int>> recent;
  unordered_map<int, list<pair<int, int>>::iterator> present;
  LRUCache(int capacity) {
    this->cap = capacity;
  }

  int get(int key) {
    if (present.find(key) == present.end()) {
      return -1;
    } else {
      int val = present[key]->second;
      recent.erase(present[key]);
      recent.push_back({key, val});
      present[key] = --recent.end();
      return val;
    }
  }

  void put(int key, int value) {
    if (present.find(key) == present.end()) {
      if (recent.size() == cap) {
        int remkey = recent.front().first;
        recent.pop_front();
        present.erase(remkey);
      }
    } else {
      recent.erase(present[key]);
    }
    recent.push_back({key, value});
    present[key] = --recent.end();
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

