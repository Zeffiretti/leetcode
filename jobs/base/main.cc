#include <iostream>
#include <vector>
#include "jobs/microsoft/fractionsum.h"
#include "jobs/microsoft/practice.h"
#include "jobs/microsoft/reducepollution.h"
#include "jobs/microsoft/rehabitalition.h"

#define UNUSED(X) (void)(X)

int main(int argc, char** argv) {
  UNUSED(argc);
  UNUSED(argv);
  int n = 100000;
  std::vector<int> numerators(n);
  std::vector<int> denominators(n, 1000000000);
  for (int i = 0; i < numerators.size() / 2; ++i) {
    numerators[i] = i;
  }
  for (int i = numerators.size() / 2; i < numerators.size(); ++i) {
    numerators[i] = 1000000000 - numerators[i - numerators.size() / 2] - 1;
  }
  int res = fractionsum::solution(numerators, denominators);
  std::cout << "res: " << res << std::endl;

  std::vector<int> A = {4, 2, 3, 7};
  res = rehabitalition::solution(A, 2, 2);
  std::cout << "res: " << res << std::endl;
  return 0;
}