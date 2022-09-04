#include <iostream>
#include <string>
#include <vector>

#include "jobs/jd/forgerycount.h"
#include "jobs/jd/opscount.h"
#include "jobs/jd/validparenthesweight.h"

#define UNUSED(X) (void)(X)

int main(int argc, char** argv) {
  // int n;
  // std::cin >> n;
  // std::vector<int> nums(n);
  // for (int i = 0; i < n; ++i) {
  //   std::cin >> nums[i];
  // }
  // std::cout << minOperation(nums) << std::endl;

  std::string s;
  std::cin >> s;
  std::cout << sumOfWeight(s) << std::endl;
  return 0;
}