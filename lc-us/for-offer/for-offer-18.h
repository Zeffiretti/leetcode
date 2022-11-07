#include <stack>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* deleteNode(ListNode* head, int val) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode* cur = head;
    ListNode* prev = nullptr;
    while (cur) {
      if (cur->val == val) {
        if (prev == nullptr) {
          head = head->next;
        } else {
          prev->next = cur->next;
        }
        break;
      }
      prev = cur;
      cur = cur->next;
    }
    return head;
  }
};