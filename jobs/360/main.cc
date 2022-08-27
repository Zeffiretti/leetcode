#include <iostream>
#include <string>
#include <vector>

#include "jobs/360/dnafix.h"
#include "jobs/360/paveroad.h"

#define UNUSED(X) (void)(X)

int main(int argc, char** argv) {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> sources;
  std::vector<int> dests;
  std::vector<int> weights;
  for (int i = 0; i < m; ++i) {
    int val;
    std::cin >> val;
    sources.push_back(val);
  }
  for (int i = 0; i < m; ++i) {
    int val;
    std::cin >> val;
    dests.push_back(val);
  }
  for (int i = 0; i < m; ++i) {
    int val;
    std::cin >> val;
    weights.push_back(val);
  }
  PaveRoad paveroad;
  std::cout << paveroad.solution(sources, dests, weights, n, m);
  return 0;
}