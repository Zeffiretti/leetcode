#ifndef JOBS_JD_REPLACE_STRING
#define JOBS_JD_REPLACE_STRING
#include <iostream>
#include <string>
#include <vector>

int distanceBetweenLetters(char a, char b) {
  if (std::islower(a) && std::islower(b)) {
    return (b - a >= 0) ? (b - a) : (26 + (b - a));
  }
  if (std::isupper(a) && std::isupper(b)) {
    return (b - a >= 0) ? (b - a) : (26 + (b - a));
  }
  return 1 + distanceBetweenLetters(std::tolower(a), std::tolower(b));
}

int distanceBetweenString(const std::string& s1, const std::string& s2) {
  int res = 0;
  for (int i = 0; i < s1.size(); ++i) {
    res += distanceBetweenLetters(s1[i], s2[i]);
  }
  return res;
}

#endif /* JOBS_JD_REPLACE_STRING */
