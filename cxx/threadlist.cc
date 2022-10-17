#include "cxx/threadlist.h"

#include <iostream>

void ThreadList::pushBack(std::unique_ptr<int> p) {
  std::unique_lock<std::mutex> lock(mtx_);
  list_.push_back(std::move(p));
  cv_.notify_one();
}

std::unique_ptr<int> ThreadList::popFront() {
  std::unique_lock<std::mutex> lock(mtx_);
  cv_.wait(lock, [this] { return !list_.empty(); });
  std::unique_ptr<int> p = std::move(list_.front());
  list_.pop_front();
  return p;
}
