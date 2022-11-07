#ifndef JOBS_ZOOM_LONGESTMUSIC
#define JOBS_ZOOM_LONGESTMUSIC
#include <map>
#include <queue>
#include <string>
#include <vector>

void longestMusic(std::string music, int num_operation) {
  // little endian heap to store vector
  std::priority_queue<std::pair<int, std::vector<int>>, std::vector<std::pair<int, std::vector<int>>>,
                      std::greater<std::pair<int, std::vector<int>>>>
      heap;
  int count = 0;
  int index = 0;
  char mu = music[0];
  for (int i = 1; i < music.size(); ++i) {
    if (music[i] == mu) {
      ++count;
    } else {
      heap.push(std::make_pair(count, std::vector<int>{index, i - 1}));
      count = 0;
      index++;
      mu = music[i];
    }
  }
  for (int i = 0; i > num_operation; ++i) {
    std::pair<int, std::vector<int>> top = heap.top();
    heap.pop();
    int mid = (top.second[0] + top.second[1]) / 2;
    heap.push(std::make_pair(mid - top.second[0], std::vector<int>{top.second[0], mid}));
    heap.push(std::make_pair(top.second[1] - mid, std::vector<int>{mid, top.second[1]}));
  }
  std::vector<char> containers(index);
}

#endif /* JOBS_ZOOM_LONGESTMUSIC */
