// created by Hiesh on Mar. 10, 2022

#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include <cmath>
#include <string>
#include <vector>

namespace mAlg {
// quick sort partition
template <typename T>
int partition(std::vector<T>& nums, int left, int right) {
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

// quick sort
template <typename T>
void quickSort(std::vector<T>& nums, int left, int right) {
  if (left >= right) return;
  int pivot = partition(nums, left, right);
  quickSort(nums, left, pivot - 1);
  quickSort(nums, pivot + 1, right);
}

// random partition
template <typename T>
int randomPartition(std::vector<T>& nums, int left, int right) {
  int pivot = left + rand() % (right - left + 1);
  std::swap(nums[pivot], nums[left]);
  return partition(nums, left, right);
}

// random quick sort
template <typename T>
void randomQuickSort(std::vector<T>& nums, int left, int right) {
  if (left >= right) return;
  int pivot = randomPartition(nums, left, right);
  randomQuickSort(nums, left, pivot - 1);
  randomQuickSort(nums, pivot + 1, right);
}

// binary search
template <typename T>
int binarySearch(std::vector<T>& nums, int left, int right, T target) {
  if (left > right) return -1;
  int mid = left + (right - left) / 2;
  if (nums[mid] == target) return mid;
  if (nums[mid] > target) return binarySearch(nums, left, mid - 1, target);
  return binarySearch(nums, mid + 1, right, target);
}

// heapify method
template <typename T>
void heapify(std::vector<T>& nums, int size, int i) {
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

// heapsort nums
template <typename T>
void heapSort(std::vector<T>& nums) {
  int size = nums.size();
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(nums, size, i);
  }
  for (int i = size - 1; i >= 0; i--) {
    std::swap(nums[0], nums[i]);
    heapify(nums, i, 0);
  }
}

// counting sort
template <typename T>
void countingSort(std::vector<T>& nums) {
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
void radixSort(std::vector<T>& nums) {
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

// Radix sort with bucket
template <typename T>
void radixSortWithBucket(std::vector<T>& nums) {
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
  std::vector<std::vector<T>> bucket(10, std::vector<T>());
  for (int i = 0; i < nums.size(); i++) {
    int digit = int(nums[i] / pow(10, max_digit - 1)) % 10;
    bucket[digit].push_back(nums[i]);
  }
  int index = 0;
  for (int i = 0; i < bucket.size(); i++) {
    for (int j = 0; j < bucket[i].size(); j++) {
      nums[index++] = bucket[i][j];
    }
  }
}

// Radix sort with counting sort
template <typename T>
void radixSortWithCountingSort(std::vector<T>& nums) {
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

// select ith smallest of nums using Randomized divide-and-conquer algorithm
template <typename T>
T select(std::vector<T>& nums, int i) {
  int left = 0;
  int right = nums.size() - 1;
  while (left <= right) {
    int pivot = partition(nums, left, right);
    if (pivot == i) {
      return nums[pivot];
    } else if (pivot < i) {
      left = pivot + 1;
    } else {
      right = pivot - 1;
    }
  }
  return -1;
}

// rand partition for select
// template <typename T>
// int partition(std::vector<T> &nums, int left, int right) {
//   int pivot = rand() % (right - left + 1) + left;
//   std::swap(nums[pivot], nums[right]);
//   int i = left;
//   for (int j = left; j < right; j++) {
//     if (nums[j] <= nums[right]) {
//       std::swap(nums[i], nums[j]);
//       i++;
//     }
//   }
//   std::swap(nums[i], nums[right]);
//   return i;
// }

// select ith smallest of nums using dividing them into 5 groups
template <typename T>
T selectWithGroups(std::vector<T>& nums, int i) {
  // divide nums into 5 froups
  int group_size = nums.size() / 5;
  std::vector<std::vector<T>> groups(5, std::vector<T>());
  for (int i = 0; i < nums.size(); i++) {
    groups[i / group_size].push_back(nums[i]);
  }
  // recursicely select the median of each group to be pivot
  for (int i = 0; i < groups.size(); i++) {
    groups[i] = {select(groups[i], groups[i].size() / 2)};
  }
  // partition the groups around the pivot x, let k=rank(x)
  // if k < i, recursively select the (i-k)th smallest of the right group
  // if k == i, then x is the ith smallest
  // if k > i, recursively select the ith smallest of the left group
  std::vector<T> pivot(groups.size());
  for (int i = 0; i < groups.size(); i++) {
    pivot[i] = groups[i][0];
  }
  int k = partition(pivot, 0, pivot.size() - 1);
  if (k == i) {
    return pivot[k];
  } else if (k < i) {
    return selectWithGroups(groups[k], i - k);
  } else {
    return selectWithGroups(groups[k + 1], i - k - 1);
  }
  return -1;
}

// select ith smallest of nums using Randomized divide-and-conquer algorithm
// input: nums is a vector of type T
//        p: start index
//        q: end index
//        i: rank
// output: the ith smallest element
template <typename T>
T select(std::vector<T>& nums, int p, int q, int i) {
  if (p == q) {
    return nums[p];
  }
  int pivot = partition(nums, p, q);
  int k = pivot - p + 1;
  if (i == k) {
    return nums[pivot];
  } else if (i < k) {
    return select(nums, p, pivot - 1, i);
  } else {
    return select(nums, pivot + 1, q, i - k);
  }
}

}  // namespace mAlg
#endif  // MYALGORITHM_H
