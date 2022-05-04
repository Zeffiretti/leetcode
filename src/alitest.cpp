#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>

#include "for-offer/for-offer-09.h"
#include "for-offer/for-offer-03.h"
using namespace std;


/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main(int argc, char **argv) {
  Solution s;
  vector<int> pushed = {2, 3, 1, 0, 2, 5, 3};
  cout << s.findRepeatNumber(pushed) << endl;
  return 0;
}
