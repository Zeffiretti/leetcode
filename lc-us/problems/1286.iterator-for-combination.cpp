/*
 * @lc app=leetcode id=1286 lang=cpp
 *
 * [1286] Iterator for Combination
 */
#include "utils.h"
// @lc code=start
class CombinationIterator {
 public:
  string m_characters = "";
  vector<int> indexes;
  CombinationIterator(string characters, int combinationLength) {
    indexes.clear();
    m_characters = characters;
    for (int i = 0; i < combinationLength; ++i) {
      indexes.push_back(i);
    }
  }

  string next() {
    string st;
    for (int i = 0; i < indexes.size(); ++i) {
      st.push_back(m_characters[indexes[i]]);
    }
    int move_index = indexes.size() - 1;
    for (; move_index > 0; --move_index) {
      if (indexes.at(move_index) == m_characters.size() - indexes.size() + move_index) {

      } else {
        break;
      }
    }
    indexes.at(move_index) = indexes.at(move_index) + 1;
    for (int i = 1; i + move_index < indexes.size(); ++i) {
      indexes.at(move_index + i) = indexes.at(move_index) + i;
    }
    return st;
  }

  bool hasNext() {
    return indexes.at(indexes.size() - 1) <= m_characters.size() - 1;
  }

  // void transfer(void) {
  // if (!hasNext()) {
  //   return;
  // }

  // }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

int main(int argc, char **argv) {
  CombinationIterator *itr = new CombinationIterator("abcdefg", 1);
  while (itr->hasNext()) {
    cout << itr->next().c_str() << endl;
  }
  cout << "finished." << endl;
  return 0;
}
