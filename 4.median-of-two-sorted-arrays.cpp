/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
 public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();
    // get medium position
    int midpos = (m + n + 1) / 2;
    int midextr = (m + n + 1) % 2;
    int max_idx = 0;
    int min_idx = 0;
    vector<int> num_long, num_short;
    if (m > n) {
      num_long = nums1;
      num_short = nums2;
      max_idx = m;
      min_idx = n;
    } else {
      num_long = nums2;
      num_short = nums1;
      max_idx = n;
      min_idx = m;
    }
    int imin = 0;
    int imax = min_idx;

    while (imin <= imax) {
      int i = (imin + imax) / 2;
      int j = midpos - 1;
      if (i < imax && num_long[j - 1] > num_short[i]) {
        //i is too small, must increase it
        imin = i + 1;
      } else if (i > 0 && num_long[j] < num_short[i - 1]) {
        imax = i - 1;
      } else {
        // i is perfect
        double max_of_left = 0;
        double min_of_right = 0;
        if (i == 0) {
          max_of_left = (double)num_long[j - 1];
        } else if (j == 0) {
          max_of_left = (double)num_short[i - 1];
        } else {
          max_of_left = (double)
                        (num_short[i - 1] > num_long[j - 1] ? num_short[i - 1] : num_long[j - 1]);
        }
        if (midextr == 0) {
          return max_of_left;
        }

        if (i == min_idx) {
          min_of_right = (double)num_long[j];
        } else if (j == max_idx) {
          min_of_right = (double)num_short[i];
        } else {
          min_of_right = (double)(num_long[j] < num_short[i] ? num_long[j] : num_short[i]);
        }

        return (max_of_left + min_of_right) / 2.0;
      }
    }
    return 0.0;
  }
};
// @lc code=end

int main(void) {
  Solution s;
  vector<int> a, b;
  a.push_back(1);
  a.push_back(3);
  b.push_back(2);
  std::cout << s.findMedianSortedArrays(a, b);
}

