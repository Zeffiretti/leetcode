#include <iostream>
#include <memory>
#include <thread>
#include <vector>

#include "concurrency/background_task.h"
#include "concurrency/thread_management.h"

#define UNUSED(x) (void)(x)

void hello() {
  std::cout << std::this_thread::get_id();
  std::cout << "Hello Concurrent World\n";
}

int main(int argc, char** argv) {
  UNUSED(argc);
  UNUSED(argv);
  // std::thread t(hello);
  // BackgroundTask task;
  // std::thread t2(task);
  // t2.detach();
  // t.detach();

  // std::thread lambda_thread([]() {
  //   std::cout << std::this_thread::get_id();
  //   std::cout << "Hello from lambda thread " << std::endl;
  // });
  // lambda_thread.detach();
  // oops();
  try {
    thread_wait();
  } catch (...) {
    std::cout << "catch exception in main thread" << std::endl;
  }
  return 0;
}
