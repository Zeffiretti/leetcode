#ifndef CONCURRENCY_THREAD_MANAGEMENT
#define CONCURRENCY_THREAD_MANAGEMENT
#include <sys/types.h>
#include <iostream>
#include <thread>
#include <vector>

void do_something(int x) { std::cout << x; }
void do_something_in_current_thread() {
  std::cout << "do_somethind_in_current_thread" << std::endl;
  throw std::runtime_error("do_something_in_current_thread");
  std::cout << "do_something_in_current_thread after exception" << std::endl;
}

struct func {
  int& i;
  func(int& i_) : i(i_) {}
  void operator()() {
    for (unsigned j = 0; j < 100; ++j) {
      do_something(i);  // there is no guarantee that i will be printed since it
                        // is shared between threads
                        // 悬空引用
    }
    std::cout << std::endl;
  }
};

void oops() {
  int some_local_state = 0;
  func my_func(some_local_state);
  std::thread my_thread(my_func);
  my_thread.detach();  // detach the thread from the main thread
  // once exit the scope, `some_local_state` will be destroyed, and in my_thread, it will be a dangling reference
  // how to fix this?
  // 1. pass by value
  // 2. pass by reference and use `std::ref`
  // 3. copy the data to the new thread, instead of sharing the data
}

void thread_wait() {
  int some_local_state = 0;
  func my_func(some_local_state);
  std::thread my_thread(my_func);
  try {
    do_something_in_current_thread();
  } catch (...) {
    std::cout << "catch exception in main thread" << std::endl;
    my_thread.join();
    throw;
  }
  my_thread.join();
}

class ThreadGuard {
 public:
  explicit ThreadGuard(std::thread& t_) : t(t_) {}
  ~ThreadGuard() {
    if (t.joinable()) {
      t.join();
    }
  }
  // The copy constructor and copy assignment operator are deleted
  // It is dangerous to copy a thread object or to assign a thread object to another
  // thread object, because the already joined thread object could be lost
  ThreadGuard(ThreadGuard const&) = delete;
  ThreadGuard& operator=(ThreadGuard const&) = delete;

 private:
  std::thread& t;
};

// When exit the scope, the local variables will be destroyed in the reverse order,
// so the ThreadGuard will be destroyed first, with calling ~ThreadGuard, which
// will call join() on the thread. Even if an exception is thrown in the
// `do_something_in_current_thread`, the thread will still be joined.
void thread_guard_func() {
  int some_local_state = 0;
  func my_func(some_local_state);
  std::thread t(my_func);
  ThreadGuard g(t);
  do_something_in_current_thread();
}

class ThreadManagement {
 public:
  ThreadManagement() = default;
  virtual ~ThreadManagement() = default;

 private:
};

#endif /* CONCURRENCY_THREAD_MANAGEMENT */
