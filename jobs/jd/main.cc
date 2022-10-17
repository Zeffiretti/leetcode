#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "jobs/jd/forgerycount.h"
#include "jobs/jd/opscount.h"
#include "jobs/jd/validparenthesweight.h"

#include "jobs/jd/max_num_factor.h"
#include "jobs/jd/replace_string.h"

#define UNUSED(X) (void)(X)

int main(int argc, char** argv) {
  UNUSED(argc);
  UNUSED(argv);
  std::string s1, s2;
  std::cin >> s1 >> s2;
  int distance = distanceBetweenString(s1, s2);
  std::cout << distance << std::endl;
  return 0;
}