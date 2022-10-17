#ifndef CONCURRENCY_BACKGROUND_TASK
#define CONCURRENCY_BACKGROUND_TASK
#include <iostream>
#include <thread>

class BackgroundTask {
 public:
  BackgroundTask() = default;
  virtual ~BackgroundTask() = default;
  void operator()() const {
    std::cout << std::this_thread::get_id();
    std::cout << "Hello from BackgroundTask" << std::endl;
  }
};

#endif /* CONCURRENCY_BACKGROUND_TASK */
