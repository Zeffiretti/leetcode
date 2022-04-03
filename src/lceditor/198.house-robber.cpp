/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */
#include "utils.h"
// @lc code=start
class Solution {
 public:
  int rob(vector<int> &nums) {
    //2 variable ->
    // in : max sum including current element
    //ex : max sum excluding current element
    int in = nums.front(), ex = 0;
    //now we iterate from 2nd house to end
    for (int i = 1; i < nums.size(); ++i) {
      //the current element can only be included when last was skipped
      //thus, it is added to ex
      int nin = ex + nums[i];
      //if we are excluding the current element , then our ans will be
      //maximum of previously calculated  values
      int nex = max(ex, in);
      //update in and ex accordingly
      in = nin, ex = nex;
    }
    //max of both will give us our required answer
    return max(in, ex);
  }
};


// @lc code=end

