#include <iostream>
#include <vector>
using namespace std;


// my queue implementation
template <typename T>
struct ListNode {
  T val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(T x) : val(x), next(nullptr) {}
  ListNode(T x, ListNode *next) : val(x), next(next) {}
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
      ListNode<T> *tmp = head;
      head = head->next;
      delete tmp;
    }
  }
  void push(T val) {
    ListNode<T> *tmp = new ListNode<T>(val);
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
    ListNode<T> *tmp = head;
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
  ListNode<int> *head;
  ListNode<int> *tail;
};


int main() {
  //一个队列
  MyQueue<int> queue;
  queue.push(1);
  queue.push(2);
  queue.push(3);
  queue.push(4);
  queue.push(5);
  cout << queue.front() << endl;
  cout << queue.back() << endl;
  cout << "-----" << endl;

  //pop them
  cout << queue.pop() << endl;
  cout << queue.pop() << endl;
  cout << "-----" << endl;
  cout << queue.front() << endl;
  cout << queue.back() << endl;

  return 0;
}