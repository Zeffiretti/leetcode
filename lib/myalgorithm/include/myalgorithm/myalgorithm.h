// created by Hiesh on Mar. 10, 2022


#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include <vector>
#include <string>
#include <cmath>

namespace mAlg {
//quick sort partition
template <typename T>
int partition(std::vector<T> &nums, int left, int right) {
  int pivot = nums[left];
  int i = left;
  int j = right + 1;
  while (true) {
    while (nums[++i] < pivot) {
      if (i == right) break;
    }
    while (nums[--j] > pivot) {
      if (j == left) break;
    }
    if (i >= j) break;
    std::swap(nums[i], nums[j]);
  }
  std::swap(nums[left], nums[j]);
  return j;
}

//quick sort
template <typename T>
void quickSort(std::vector<T> &nums, int left, int right) {
  if (left >= right) return;
  int pivot = partition(nums, left, right);
  quickSort(nums, left, pivot - 1);
  quickSort(nums, pivot + 1, right);
}

//heapify method
template <typename T>
void heapify(std::vector<T> &nums, int size, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < size && nums[left] > nums[largest]) {
    largest = left;
  }
  if (right < size && nums[right] > nums[largest]) {
    largest = right;
  }
  if (largest != i) {
    std::swap(nums[i], nums[largest]);
    heapify(nums, size, largest);
  }
}

//heapsort nums
template <typename T>
void heapSort(std::vector<T> &nums) {
  int size = nums.size();
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(nums, size, i);
  }
  for (int i = size - 1; i >= 0; i--) {
    std::swap(nums[0], nums[i]);
    heapify(nums, i, 0);
  }
}

//counting sort
template <typename T>
void countingSort(std::vector<T> &nums) {
  // find the max number
  int max_num = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] > max_num) {
      max_num = nums[i];
    }
  }
  // count phase
  std::vector<int> count(max_num + 1, 0);
  for (int i = 0; i < nums.size(); i++) {
    count[nums[i]]++;
  }
  for (int i = 1; i < count.size(); i++) {
    count[i] += count[i - 1];
  }
  std::vector<T> sorted(nums.size());
  for (int i = nums.size() - 1; i >= 0; i--) {
    sorted[count[nums[i]] - 1] = nums[i];
    count[nums[i]]--;
  }
  nums = sorted;
}

// Radix sort
template <typename T>
void radixSort(std::vector<T> &nums) {
  int max_num = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] > max_num) {
      max_num = nums[i];
    }
  }
  int max_digit = 0;
  while (max_num) {
    max_num /= 10;
    max_digit++;
  }
  for (int i = 0; i < max_digit; i++) {
    std::vector<int> count(10, 0);
    for (int j = 0; j < nums.size(); j++) {
      int digit = int(nums[j] / pow(10, i)) % 10;
      count[digit]++;
    }
    for (int j = 1; j < count.size(); j++) {
      count[j] += count[j - 1];
    }
    std::vector<T> sorted(nums.size());
    for (int j = nums.size() - 1; j >= 0; j--) {
      int digit = int(nums[j] / pow(10, i)) % 10;
      sorted[count[digit] - 1] = nums[j];
      count[digit]--;
    }
    nums = sorted;
  }
}

}  // namespace mAlg
#endif // MYALGORITHM_H
