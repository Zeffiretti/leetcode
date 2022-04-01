#include <iostream>
#include <vector>
using namespace std;


// my queue implementation

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// my queue implementation
template <typename T>
class MyQueue {
 public:
  MyQueue() {
    head = tail = nullptr;
  }
  ~MyQueue() {
    while (head) {
      ListNode *tmp = head;
      head = head->next;
      delete tmp;
    }
  }
  void push(T val) {
    ListNode *tmp = new ListNode(val);
    if (tail) {
      tail->next = tmp;
    }
    tail = tmp;
    if (!head) {
      head = tail;
    }
  }
  T pop() {
    if (!head) {
      return -1;
    }
    T val = head->val;
    ListNode *tmp = head;
    head = head->next;
    delete tmp;
    if (!head) {
      tail = nullptr;
    }
    return val;
  }
  T front() {
    if (!head) {
      return -1;
    }
    return head->val;
  }
  T back() {
    if (!tail) {
      return -1;
    }
    return tail->val;
  }
  bool empty() {
    return !head;
  }
 private:
  ListNode *head;
  ListNode *tail;
};


int main() {
  //一个队列
  MyQueue<int> queue;
  queue.push(1);
  queue.push(2);
  queue.push(3);
  queue.push(4);

  //pop them
  cout << queue.pop() << endl;
  cout << queue.pop() << endl;

  return 0;
}