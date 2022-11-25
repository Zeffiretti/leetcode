#include <stack>
#include <string>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  std::vector<int> reversePrint(ListNode* head) {
    std::stack<int> st;
    while (head) {
      st.push(head->val);
      head = head->next;
    }
    std::vector<int> res;
    while (!st.empty()) {
      res.push_back(st.top());
      st.pop();
    }
    return res;
  }
};