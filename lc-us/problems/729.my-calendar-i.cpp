/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */
#include <utility>
#include "utils.h"
// @lc code=start
class MyCalendar {
 public:
  MyCalendar() = default;

  bool book(int start, int end) {
    if (events.empty()) {
      events.emplace_back(make_pair(start, end));
      return true;
    }
    if (events[0].first >= end) {
      events.emplace(events.begin(), make_pair(start, end));
      return true;
    }
    int index = 0;
    while (index < events.size() && events[index].second <= start) index++;
    if (index == events.size()) {
      events.emplace_back(make_pair(start, end));
      return true;
    }
    if (events[index].first >= end) {
      events.emplace(events.begin() + index, make_pair(start, end));
      return true;
    }
    return false;
  }

 private:
  vector<pair<int, int>> events;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end
