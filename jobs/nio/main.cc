#include <stdio.h>
#include <string.h>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "jobs/nio/binarysearchtreecount.h"
#include "jobs/nio/daycalculator.h"
#include "jobs/nio/stockprices.h"

int main() {
  size_t nBytes = 100;
  char* ch;
  DayCalculator dc;
  ch = (char*)malloc(nBytes + 1);
  ch[0] = '\0';
  // 逐行读取输入字符串，并调用dc.calc(), 遇到空行结束
  while (getline(&ch, &nBytes, stdin) != 0) {
    if (strlen(ch) <= 0) {
      break;
    }
    dc.calc(ch);
    ch[0] = '\0';
  }
  return 0;
}