/*
 * @lc app=leetcode id=878 lang=cpp
 *
 * [878] Nth Magical Number
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  static long long int gcd(long long int a, long long int b) {
    if (b == 0)
      return a;
    return gcd(b, a % b);
  }
  static long long int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
  }

  int nthMagicalNumber(int n, int a, int b) {
    int m = pow(10, 9) + 7;
    if (a > b) swap(a, b);


    //start of search space is smaller amon a,b and and end is b*n
    long long int s = (long long int)(a), e = (long long int)(n) * (long long int)(b), sum, l;

    //this is to handle duplicate elements
    l = lcm(a, b);
    sum = (l / a) + (l / b);


    while (s <= e) {
      long long int mid, total = 0;
      mid = s - (s - e) / 2;

      //total denotes elements smaller than mid in multiples of a and b
      total = (mid % a == 0) ? (mid / a) - 1 : mid / a;
      total += (mid % b == 0) ? (mid / b) - 1 : mid / b;

      //to remove duplicates
      if (total >= sum) total -= (total / sum);

      //now binary search

      //if total is equal to n-1 and mid is divivsible by any one of a and b
      if (total == n - 1 && (mid % a == 0 || mid % b == 0))
        return mid % m;
      //if total is less than mid
      else if (total <= n - 1)
        s = mid + 1;
      else
        e = mid - 1;
    }
    return -1;
  }
};
// @lc code=end

