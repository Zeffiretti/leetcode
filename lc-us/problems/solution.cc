#include <vector>
#include "lc-us/problems/605.can-place-flowers.cpp"
#include "lc-us/problems/utils.h"

int main(int argc, char* argv[]) {
  vector<int> flowerbed;
  flowerbed.push_back(0);
  flowerbed.push_back(0);
  flowerbed.push_back(0);
  flowerbed.push_back(1);
  flowerbed.push_back(0);
  flowerbed.push_back(0);
  flowerbed.push_back(0);
  flowerbed.push_back(0);
  flowerbed.push_back(0);
  flowerbed.push_back(0);

  Solution s;
  cout << s.canPlaceFlowers(flowerbed, 1) << endl;
  return 0;
}