#ifndef JOBS_WATERDROP_SUBSTRCOUNT
#define JOBS_WATERDROP_SUBSTRCOUNT

#include <cstring>
#include <iostream>
using namespace std;
int subStrCount(const char* str, const char* subStr) {
  int count = 0;
  int subStrLen = strlen(subStr);
  int strLen = strlen(str);
  for (int i = 0; i < strLen; i++) {
    if (strncmp(str + i, subStr, subStrLen) == 0) {
      count++;
    }
  }
  return count;
}

#endif /* JOBS_WATERDROP_SUBSTRCOUNT */
