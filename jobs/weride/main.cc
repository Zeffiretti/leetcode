#include <stdio.h>
#include <iostream>
#include <vector>

#include "jobs/weride/maxvalue.h"
#include "jobs/weride/minimummagic.h"
#include "jobs/weride/reachend.h"

#define UNUSED(X) (void)(X)

int main(int argc, char** argv) {
  std::vector<ll> steps;
  ll n;
  while (scanf("%lld", &n) != EOF) {
    steps.emplace_back(n);
    if (std::cin.get() == ',') {
      continue;
    } else {
      break;
    }
  }
  int count = jumpToEnd(steps);
  std::cout << count << std::endl;
  return 0;
}