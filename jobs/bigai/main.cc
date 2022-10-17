#include <iostream>
#include <list>
#include <vector>

#define UNUSED(X) (void)(X)

int main(int argc, char** argv) {
  UNUSED(argc);
  UNUSED(argv);
  std::vector<int> container(15, 0);
  std::cout << "size: " << container.size() << ", capacity: " << container.capacity() << std::endl;
  for (int i = 0; i < 20; ++i) {
    container.push_back(i);
    std::cout << "size: " << container.size() << ", capacity: " << container.capacity() << std::endl;
  }

  return 0;
}