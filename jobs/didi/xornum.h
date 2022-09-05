#ifndef JOBS_DIDI_XORNUM
#define JOBS_DIDI_XORNUM

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> beauties(70001);

void buildBeauty() {
  for (int i = 0; i < 10; ++i) {
    beauties[i] = i;
  }
  for (int i = 10; i < 70001; ++i) {
    int div = i / 10;
    int mod = i % 10;
    beauties[i] = beauties[div] ^ mod;
  }
  std::fstream fs("beauties2.txt", std::ios::out);
  fs << "std::vector<int> beauties = {";
  for (int i = 0; i < 70000; ++i) {
    fs << beauties[i] << ",";
  }
  fs << beauties[70000] << "};";
  fs.close();
}

int countOfBeautyNum(int minimum, int maxmium, int beauty) {
  // [minimum, maxmium).
  buildBeauty();
  auto max_elem = std::max_element(beauties.begin(), beauties.end());
  int max_beauty = *max_elem;
  std::cout << "max_beauty: " << max_beauty << std::endl;
  int res = 0;
  // for (int i = minimum; i <= maxmium; ++i) {
  //   if (beauties[i] == beauty) {
  //     res++;
  //   }
  // }
  return res;
}

#endif /* JOBS_DIDI_XORNUM */
