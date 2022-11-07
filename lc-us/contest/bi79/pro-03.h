#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class BookMyShow {
 public:
  BookMyShow(int n, int m) {
    // init seats with n elements of m
    seats.resize(n);
    for (int i = 0; i < n; ++i) {
      seats[i].resize(2);
      seats[i][0] = i;
      seats[i][1] = m;
    }
    m_ = m;
  }

  vector<int> gather(int k, int maxRow) {
    if (seats.empty()) return {};
    for (int i = 0; i < seats.size(); ++i) {
      vector<int> seat = seats[i];
      if (seat[0] > maxRow) {
        return {};
      }
      if (seat[1] >= k) {
        int row = seat[0];
        int col = m_ - seat[1];
        seat[1] -= k;
        if (seat[1] == 0) {
          seats.erase(seats.begin() + i);
        } else {
          seats[i] = seat;
        }
        return {row, col};
      }
    }
    return {};
  }

  bool scatter(int k, int maxRow) {
    if (seats.empty()) {
      return false;
    }
    int empty_seats = 0;
    for (int i = 0; i < seats.size(); ++i) {
      vector<int> seat = seats[i];
      if (seat[0] > maxRow) {
        return false;
      }
      empty_seats += seat[1];
      if (empty_seats >= k) {
        for (int j = 0; j < i; ++j) {
          k -= seats[0][1];
          seats.erase(seats.begin());
        }
        seats[0][1] -= k;
        if (!seats.empty() && seats[0][1] == 0) {
          seats.erase(seats.begin());
        }
        return true;
      }
    }
    return false;
  }

 private:
  vector<vector<int>> seats;
  int m_;
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */