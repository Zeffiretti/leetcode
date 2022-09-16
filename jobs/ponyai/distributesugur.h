#ifndef JOBS_PONYAI_DISTRIBUTESUGUR
#define JOBS_PONYAI_DISTRIBUTESUGUR

#include <algorithm>
#include <queue>
#include <vector>

using ll = long long;

int whoGetsKthCandy(const std::vector<ll>& requirements, ll k) {
  // write your code here
  int n = requirements.size();
  std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll, ll>>, std::greater<std::pair<ll, int>>> pq;
  for (int i = 0; i < n; ++i) {
    pq.push({requirements[i], i});
  }
  int loop = 0;
  while (!pq.empty() && k > n) {
    k -= pq.top().first * n;
    loop += pq.top().first;
    while (!pq.empty() && pq.top().first <= loop) {
      pq.pop();
      n--;
    }
  }
  std::vector<int> remain_persons;
  while (!pq.empty()) {
    remain_persons.push_back(pq.top().second);
    pq.pop();
  }
  std::sort(remain_persons.begin(), remain_persons.end());
  return remain_persons[k - 1] + 1;
}

#endif /* JOBS_PONYAI_DISTRIBUTESUGUR */
