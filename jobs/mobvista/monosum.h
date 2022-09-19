#ifndef JOBS_MOBVISTA_MONOSUM
#define JOBS_MOBVISTA_MONOSUM
#include <iostream>
#include <vector>

int count = 0;

void merge(std::vector<int>& arr, int start, int mid, int end) {
  std::vector<int> res;
  int left = start, right = mid + 1;
  while (left <= mid && right <= end) {
    if (arr[left] <= arr[right]) {
      count += (end - right + 1) * arr[left];
      count %= 1000000007;
      res.push_back(arr[left++]);
    } else {
      res.push_back(arr[right++]);
    }
  }
  while (left <= mid) {
    res.push_back(arr[left++]);
  }
  while (right <= end) {
    res.push_back(arr[right++]);
  }
  for (int i = 0; i < res.size(); i++) {
    arr[start + i] = res[i];
  }
}

void mergeSort(std::vector<int>& arr, int start, int end) {
  int mid = (start + end) / 2;
  if (mid > start) {
    mergeSort(arr, start, mid);
  }
  if (end > mid + 1) {
    mergeSort(arr, mid + 1, end);
  }
  merge(arr, start, mid, end);
}

int monoSum(std::vector<int>& nums) {
  int n = nums.size();
  if (n == 0) {
    return 0;
  }
  if (n < 2) {
    return nums[0];
  }
  mergeSort(nums, 0, n - 1);
  return count;
}

#endif /* JOBS_MOBVISTA_MONOSUM */
