#ifndef JOBS_BAIDU_BAIDUSTR
#define JOBS_BAIDU_BAIDUSTR
#include <iostream>
#include <string>
#include <vector>

bool isOval(const char& c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }

bool baidu[] = {false, true, true, false, true};
int next[] = {0, 0, 0, 1, 2};

bool isBaiduType(const std::string& s, int& nxt) {
  std::vector<bool> used(26, false);
  for (int i = 1; i < 5; ++i) {
    char c = s[i];
    if (used[c - 'a'] || isOval(s[i]) != baidu[i]) {
      nxt = next[i];
      return false;
    }
    used[c - 'a'] = true;
  }
  nxt = next[4];
  return true;
}

int baiduTypeSubstr(const std::string& s) {
  int res = 0;
  for (int i = 0; i < s.size() - 5; i++) {
    if (!isOval(s[i])) {
      int nxt = 0;
      if (isBaiduType(s.substr(i, 5), nxt)) {
        res++;
      }
      i += nxt;
    }
  }
  return res;
}

#endif /* JOBS_BAIDU_BAIDUSTR */
