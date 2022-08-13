#ifndef JOBS_MICROSOFT_BINARYGAP
#define JOBS_MICROSOFT_BINARYGAP

#include <cstdint>
uint8_t int2uint8(int n) { return n & 0xff; }

int solution(int N) {
  // write your code in C++14 (g++ 6.2.0)
  uint8_t binary[32] = {0};
  int i = 0;
  while (N > 0) {
    binary[i++] = int2uint8(N & 1);
    N >>= 1;
  }
  int max_gap = 0;
  int cur_gap = 0;
  int j = 0;
  while (binary[j] == 0) {
    ++j;
  }
  for (int i = j + 1; i < 32; ++i) {
    if (binary[i] == 1) {
      if (cur_gap > max_gap) {
        max_gap = cur_gap;
      }
      cur_gap = 0;
    } else {
      ++cur_gap;
    }
  }
  return max_gap;
}

#endif /* JOBS_MICROSOFT_BINARYGAP */
