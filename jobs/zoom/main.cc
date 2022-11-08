#include <iostream>
#include <vector>

#include "jobs/zoom/monica.h"

#define UNUSED(X) (void)(X)

int main(int argc, char** argv) {
  UNUSED(argc);
  UNUSED(argv);
  int a, b;
  int n;
  std::cin >> a >> b >> n;
  for (int i = 0; i < n; ++i) {
    char op;
    int val;
    std::cin >> op >> val;
    if (op == '+') {
      if (val >= 0) {
        if (a >= b) {
          a += val;
        } else {
          b += val;
        }
      } else {
        if (a >= b) {
          b += val;
        } else {
          a += val;
        }
      }
    } else {
      if (val >= 0) {
        if (a >= b) {
          b -= val;
        } else {
          a -= val;
        }
      } else {
        if (a >= b) {
          a -= val;
        } else {
          b -= val;
        }
      }
    }
  }
  std::cout << a << " " << b << std::endl;
  return 0;
}