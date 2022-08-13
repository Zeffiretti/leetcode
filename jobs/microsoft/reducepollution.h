#ifndef JOBS_MICROSOFT_REDUCEPOLLUTION
#define JOBS_MICROSOFT_REDUCEPOLLUTION
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace reducepollution {

void binary_insert(vector<double>& pollute, int val) {
  int left = 0, right = pollute.size() - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (pollute[mid] == val) {
      pollute.insert(pollute.begin() + mid, val);
      return;
    } else if (pollute[mid] > val) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  pollute.insert(pollute.begin() + left, val);
}

int solution(vector<int>& A_in) {
  // write your code in C++ (C++14 (g++ 6.2.0))
  if (A_in.size() <= 1) {
    return 1;
  }
  vector<double> A(A_in.size());
  long long pollute_sum = 0;
  for (int i = 0; i < A.size(); i++) {
    A[i] = A_in[i];
    pollute_sum += A[i];
  }
  double reduce_target = 0.5 * pollute_sum;
  // sort the array in descending order
  sort(A.begin(), A.end(), greater<int>());
  double reduced_pollute = 0.0;
  int filter_num = 0;
  while (reduced_pollute < reduce_target) {
    filter_num++;
    reduced_pollute += 0.5 * A[0];
    A[0] = 0.5 * A[0];
    if (A[0] < A[1]) {
      // move A[] to the proper position, such that A is descending order
      int tmp = A[0];
      A.erase(A.begin());
      binary_insert(A, tmp);
    }
  }
  return filter_num;
}
}  // namespace reducepollution

#endif /* JOBS_MICROSOFT_REDUCEPOLLUTION */
