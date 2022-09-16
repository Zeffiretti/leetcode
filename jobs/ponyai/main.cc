#include <iostream>
#include <vector>

#include "jobs/ponyai/distributesugur.h"
#include "jobs/ponyai/maxstep.h"
#include "jobs/ponyai/ponycount.h"

#define UNUSED(X) (void)(X)

int main(int argc, char** argv) {
  UNUSED(argc);
  UNUSED(argv);
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  std::cout << ponyCount(str) << std::endl;
  return 0;
}