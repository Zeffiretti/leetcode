#ifndef CXX_THREADLIST
#define CXX_THREADLIST
#include <condition_variable>
#include <list>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

class ThreadList {
 public:
  ThreadList() = default;
  ~ThreadList() = default;
  void pushBack(std::unique_ptr<int> p);
  std::unique_ptr<int> popFront();

 private:
  std::list<std::unique_ptr<int>> list_;
  std::mutex mtx_;
  std::condition_variable cv_;
};

#endif /* CXX_THREADLIST */
