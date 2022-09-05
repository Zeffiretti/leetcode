#include <iostream>
#include <vector>

#include "jobs/didi/validpeach.h"
#include "jobs/didi/xornum.h"

#define UNUSED(X) (void)(X)

int main(int argc, char** argv) {
  int t;
  std::cin >> t;
  std::vector<int> limits_min(t);
  std::vector<int> limits_max(t);
  for (int i = 0; i < t; ++i) {
    std::cin >> limits_min[i] >> limits_max[i];
  }
  std::vector<int> beauties(t);
  for (int i = 0; i < t; ++i) {
    std::cin >> beauties[i];
  }
  for (int i = 0; i < t; ++i) {
    std::cout << countOfBeautyNum(limits_min[i], limits_max[i], beauties[i]) << " ";
  }
}