#include <string.h>
#include <cstdio>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "jobs/nio/binarysearchtreecount.h"
#include "jobs/nio/daycalculator.h"
#include "jobs/nio/stockprices.h"

int main() {
  char ch[100];
  memset(ch, 0, sizeof(ch));
  DayCalculator dc;
  // 逐行读取输入字符串，并调用dc.calc()
  while (scanf("%s", ch) != EOF) {
    if (std::string(ch) == "exit") {
      break;
    }
    dc.calc(ch);
    ch[0] = '\0';
  }
  return 0;
}