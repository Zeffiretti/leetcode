#ifndef JOBS_NIO_DAYCALCULATOR
#define JOBS_NIO_DAYCALCULATOR
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

class DayCalculator {
 public:
  DayCalculator() = default;
  ~DayCalculator() = default;
  int solution(int n);
  struct Date {
    int year;
    int month;
    int day;
    Date() : year(0), month(0), day(0) {}
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    bool operator<(const Date& other) const {
      if (year != other.year) {
        return year < other.year;
      }
      if (month != other.month) {
        return month < other.month;
      }
      return day < other.day;
    }
    bool operator==(const Date& other) const { return year == other.year && month == other.month && day == other.day; }
  };
  void calc(const std::string& s) {
    Date date = parseStringToDate(s);
    if (!isDateLegal(date)) {
      std::cout << "illegal" << std::endl;
      return;
    }
    int days = daysBetween(base_date_, date);
    days %= 7;
    if (days < 0) {
      days += 7;
    }
    std::cout << kDays[days] << std::endl;
  }

 private:
  const std::vector<std::string> kDays = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
  const std::vector<int> kDaysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  const int kDaysInNormYear = 365;
  const int kDaysInLeapYear = 366;
  Date base_date_ = Date(1, 1, 1);  // it is a Monday

  bool isLeapYear(int year) { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }

  int daysFromYearStart(const Date& date) {
    int days = 0;
    for (int i = 1; i < date.month; ++i) {
      days += kDaysInMonth[i - 1];
    }
    if (isLeapYear(date.year) && date.month > 2) {
      days += 1;
    }
    days += date.day;
    return days;
  }

  int daysBetween(const Date& date1, const Date& date2) {
    int days = 0;
    for (int i = date1.year; i < date2.year; ++i) {
      days += isLeapYear(i) ? kDaysInLeapYear : kDaysInNormYear;
    }
    days += daysFromYearStart(date2) - daysFromYearStart(date1);
    return days;
  }

  Date parseStringToDate(const std::string& date_str) {
    // date_str: "YYYY-MM-DD", but the length is not checked
    int year, month, day;
    std::string::size_type pos = date_str.find('-');
    year = std::stoi(date_str.substr(0, pos));
    std::string::size_type pos2 = date_str.find('-', pos + 1);
    month = std::stoi(date_str.substr(pos + 1, pos2 - pos - 1));
    day = std::stoi(date_str.substr(pos2 + 1));
    return Date(year, month, day);
  }

  bool isDateLegal(const Date& date) {
    if (date.year < 1 || date.year > 9999) {
      return false;
    }
    if (date.month < 1 || date.month > 12) {
      return false;
    }
    if (date.day < 1 || date.day > kDaysInMonth[date.month - 1]) {
      return false;
    }
    return true;
  }
};

#endif /* JOBS_NIO_DAYCALCULATOR */
