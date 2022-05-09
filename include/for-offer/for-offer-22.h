#include <vector>
#include <string>
#include <stack>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *getKthFromEnd(ListNode *head, int k) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *slow = head;
    for (int i = 0; i < k; i++) {
      slow = slow->next;
      if (slow == nullptr) {
        return nullptr;
      }
    }
    ListNode *fast = head;
    while (slow->next) {
      slow = slow->next;
      fast = fast->next;
    }
    return fast;
  }
};