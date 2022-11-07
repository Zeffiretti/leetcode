/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */
#include "utils.h"
using namespace std;
// @lc code=start
class RandomizedSet {
  vector<int> numberList;
  unordered_map<int, int> hashTable;

 public:
  /** Initialize your data structure here. */
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    if (hashTable.find(val) != hashTable.end()) {
      return false;
    }
    hashTable[val] = numberList.size();
    numberList.push_back(val);
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    if (hashTable.find(val) == hashTable.end()) {
      return false;
    }
    swap(numberList[hashTable[val]], numberList[numberList.size() - 1]);
    numberList.pop_back();
    hashTable[numberList[hashTable[val]]] = hashTable[val];
    hashTable.erase(val);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() { return numberList[rand() % numberList.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

int main(int argc, char** argv) {
  RandomizedSet randomizedSet = RandomizedSet();
  cout << randomizedSet.insert(1) << endl;    // Inserts 1 to the set. Returns true as 1 was inserted successfully.
  cout << randomizedSet.remove(2) << endl;    // Returns false as 2 does not exist in the set.
  cout << randomizedSet.insert(2) << endl;    // Inserts 2 to the set, returns true. Set now contains [1,2].
  cout << randomizedSet.getRandom() << endl;  // getRandom() should return either 1 or 2 randomly.
  cout << randomizedSet.remove(1) << endl;    // Removes 1 from the set, returns true. Set now contains [2].
  cout << randomizedSet.insert(2) << endl;    // 2 was already in the set, so return false.
  cout << randomizedSet.getRandom()
       << endl;  // Since 2 is the only number in the set, getRandom() will always return 2.
}
