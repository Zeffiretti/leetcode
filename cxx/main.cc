#include <iostream>
#include <memory>
#include <thread>
#include <vector>

#include "cxx/mem.h"
#include "cxx/threadlist.h"

#define UNUSED(x) (void)(x)

// 实现两个线程，一个线程对队列进行插入，一个线程对队列进行删除
ThreadList g_list;

void pushBack() {
  for (int i = 0; i < 100000; ++i) {
    std::unique_ptr<int> p = std::make_unique<int>(i);
    g_list.pushBack(std::move(p));
    std::cout << "pushBack " << i << std::endl;
  }
}

void popFront() {
  for (int i = 0; i < 100000; ++i) {
    std::unique_ptr<int> p = g_list.popFront();
    std::cout << "popFront " << *p << std::endl;
  }
}

int main(int argc, char** argv) {
  UNUSED(argc);
  UNUSED(argv);
  // test the threadlist
  std::thread t1(pushBack);
  std::thread t2(popFront);
  t1.detach();
  t2.join();
  return 0;
}
