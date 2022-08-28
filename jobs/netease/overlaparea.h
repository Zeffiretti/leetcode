#ifndef JOBS_NETEASE_OVERLAPAREA
#define JOBS_NETEASE_OVERLAPAREA

#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long;

bool isRectangleOverlap(int* rec1, int* rec2) {  // left top x, left top y, right bottom x, right bottom y
  return !(rec1[2] <= rec2[0] || rec1[3] <= rec2[1] || rec1[0] >= rec2[2] || rec1[1] >= rec2[3]);
}

int side(int rec1start, int rec1end, int rec2start, int rec2end) {
  int ans = 0;
  if (!(rec1start >= rec2end || rec1end <= rec2start)) {
    ans = std::min(rec1end, rec2end) - std::max(rec1start, rec2start);
  }
  return ans;
}

int overlapArea(int* rec1, int* rec2) {  // left top x, left top y, right bottom x, right bottom y
  int overlap_x = side(rec1[0], rec1[2], rec2[0], rec2[2]);
  int overlap_y = side(rec1[1], rec1[3], rec2[1], rec2[3]);
  return overlap_x * overlap_y;
}

int overlap(int argc, char** argv) {
  int T;
  std::cin >> T;
  for (int _t = 0; _t < T; ++_t) {
    int n;
    std::cin >> n;
    int rectangles[n][4];
    for (int i = 0; i < n; ++i) {
      std::cin >> rectangles[i][0] >> rectangles[i][1] >> rectangles[i][2] >> rectangles[i][3];
    }
    std::vector<bool> tested(n, false);
    ll overlap_area = 0;
    for (int i = 0; i < n; ++i) {
      if (tested[i]) {
        continue;
      }
      for (int j = i + 1; j < n; ++j) {
        if (tested[j]) {
          continue;
        }
        if (isRectangleOverlap(rectangles[i], rectangles[j])) {
          int area = std::abs(rectangles[i][2] - rectangles[i][0]) * std::abs(rectangles[i][3] - rectangles[i][1]) +
                     std::abs(rectangles[j][2] - rectangles[j][0]) * std::abs(rectangles[j][3] - rectangles[j][1]) -
                     overlapArea(rectangles[i], rectangles[j]);
          overlap_area += area;
          tested[i] = true;
          tested[j] = true;
        }
      }
    }
    std::cout << overlap_area << std::endl;
  }
  return 0;
}

#endif /* JOBS_NETEASE_OVERLAPAREA */
