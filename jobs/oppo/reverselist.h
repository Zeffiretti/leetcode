#ifndef JOBS_OPPO_REVERSELIST
#define JOBS_OPPO_REVERSELIST

struct ListNode {
  int val;
  struct ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   * #例如
#输入 {1.2,3,4,5}
#输出 {5,4,3,2,1}
   * @param head ListNode类 链表的头节点
   * @return ListNode类
   */
  ListNode* reverseList(ListNode* head) {
    // write code here
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};

#endif /* JOBS_OPPO_REVERSELIST */
