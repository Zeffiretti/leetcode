#ifndef __UTILS_H_
#define __UTILS_H_
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>
#include <unordered_set>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif