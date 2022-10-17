#include <iostream>
#include <vector>

#include "jobs/rong/longeststr.h"
#include "jobs/rong/minimum_hp.h"

#define UNUSED(X) (void)(X)

int main(int argc, char** argv) {
  UNUSED(argc);
  UNUSED(argv);

  int k, n;
  std::cin >> n >> k;
  std::vector<int> attacks(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> attacks[i];
  }
  int res = minimum_hp_required(attacks, k);
  std::cout << res << std::endl;
  return 0;
}