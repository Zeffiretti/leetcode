#ifndef JOBS_OPPO_WAKALOCKCONTRIB
#define JOBS_OPPO_WAKALOCKCONTRIB
#include <algorithm>
#include <queue>
#include <vector>

class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   * 输入参数是每个应用持有WakeLock的起始时间及结束时间，函数返回值是每个应用对总WakeLock时长的贡献值，返回值vector里面的每个元素的数值累加即为手机总的持有WakeLock的时长。
   * @param wakeLock int整型vector<vector<>>
   * vector<vector<int>>的每个元素代表某个应用的持有WakeLock的信息，内部的vector<int>，元素按照奇偶排列，偶数元素代表拿WakeLock的起始时间点，奇数代表释放WakeLock的时间点
   * @return int整型vector
   */
  std::vector<int> getWakeLockContrib(std::vector<std::vector<int>>& wakeLock) {
    // write code here
    std::vector<std::vector<int>> wakeLockIndex;
    for (int i = 0; i < wakeLock.size(); ++i) {
      for (int j = 0; j < wakeLock[i].size(); j += 2) {
        std::vector<int> index;
        index.push_back(wakeLock[i][j]);
        index.push_back(wakeLock[i][j + 1]);
        index.push_back(i);
        wakeLockIndex.push_back(index);
      }
    }
    std::vector<int> res(wakeLock.size(), 0);
    std::sort(wakeLockIndex.begin(), wakeLockIndex.end(),
              [](const std::vector<int>& a, const std::vector<int>& b) { return a[0] < b[0]; });

    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> priority_ends;
    for (int i = 0; i < wakeLockIndex.size(); ++i) {
      while (!priority_ends.empty() && priority_ends.top()[0] < wakeLockIndex[i][0]) {
        priority_ends.pop();
      }
      res[wakeLockIndex[i][2]] += priority_ends.size() * (wakeLockIndex[i][1] - wakeLockIndex[i][0]);
      priority_ends.push(wakeLockIndex[i]);
    }
    return res;
  }
};

#endif /* JOBS_OPPO_WAKALOCKCONTRIB */
