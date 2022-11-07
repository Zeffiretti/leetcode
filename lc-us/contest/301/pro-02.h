#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include "../../utils.h"
using namespace std;

#include <stdio.h>

class SmallestInfiniteSet {
 public:
  SmallestInfiniteSet() {
    begin = 1;
    removed.clear();
  }

  int popSmallest() {
    int res = begin;
    begin++;
    removed.insert(res);
    while (removed.find(begin) != removed.end()) {
      cout << "begin: " << begin << endl;
      begin++;
    }
    return res;
  }

  void addBack(int num) {
    begin = min(begin, num);
    // remove num from removed
    if (removed.find(num) != removed.end()) {
      removed.erase(num);
    }
  }
  int begin;
  set<int> removed;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */