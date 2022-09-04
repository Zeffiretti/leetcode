#ifndef JOBS_JD_VALIDPARENTHESWEIGHT
#define JOBS_JD_VALIDPARENTHESWEIGHT
#include <iostream>
#include <stack>
#include <string>
#include <vector>

int longestValidSubstring(const std::string& s) {
  std::string valid_substring;
  int left_par_count = 0;
  for (auto ch : s) {
    if (ch == '(') {
      ++left_par_count;
      valid_substring += ch;
    } else {
      if (left_par_count > 0) {
        valid_substring += ch;
        --left_par_count;
      }
    }
  }
  return valid_substring.size() - left_par_count;
}

int sumOfWeight(const std::string& s) {
  std::stack<int> left_pars;
  std::vector<int> corresponding_pars(s.size(), -1);
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(') {
      left_pars.push(i);
    } else {
      if (!left_pars.empty()) {
        corresponding_pars[left_pars.top()] = i;
        corresponding_pars[i] = left_pars.top();
        left_pars.pop();
      }
    }
  }
  std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), 0));
  for (int i = 0; i < s.size(); ++i) {
    for (int j = i; j < s.size(); ++j) {
      if (corresponding_pars[i] == j) {
        dp[i][j] = j - i + 1;
      } else {
        dp[i][j] = dp[i][j - 1] + dp[j][j];
      }
    }
  }
  return 0;
}

#endif /* JOBS_JD_VALIDPARENTHESWEIGHT */
