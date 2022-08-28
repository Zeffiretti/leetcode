#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using ll = long long;

int activate_num = 0;
struct FingerCode {
  bool connection[9][9] = {{false, false, false, false, false, false, false, false, false},
                           {false, false, false, false, false, false, false, false, false},
                           {false, false, false, false, false, false, false, false, false},
                           {false, false, false, false, false, false, false, false, false},
                           {false, false, false, false, false, false, false, false, false},
                           {false, false, false, false, false, false, false, false, false},
                           {false, false, false, false, false, false, false, false, false},
                           {false, false, false, false, false, false, false, false, false},
                           {false, false, false, false, false, false, false, false, false}};
  FingerCode() = default;
  void addConnection(int i, int j, bool* num_enable) {
    int distance = std::abs(i - j);
    if (distance == 6 || distance == 8) {
      int middle = (i + j) / 2;
      if (num_enable[middle]) {
        connection[i][middle] = true;
        connection[middle][i] = true;
        connection[j][middle] = true;
        connection[middle][j] = true;
      } else {
        connection[i][j] = true;
        connection[j][i] = true;
      }
      return;
    }
    if (distance == 2) {
      int minimum = std::min(i, j);
      if (minimum == 0 || minimum == 3 || minimum == 6) {
        int middle = (i + j) / 2;
        if (num_enable[middle]) {
          connection[i][middle] = true;
          connection[middle][i] = true;
          connection[j][middle] = true;
          connection[middle][j] = true;
        }
      } else {
        connection[i][j] = true;
        connection[j][i] = true;
      }
      return;
    }
    connection[i][j] = true;
    connection[j][i] = true;
  }
  void removeConnection(int i, int j, bool* num_enable) {
    int distance = std::abs(i - j);
    if (distance == 6 || distance == 8) {
      int middle = (i + j) / 2;
      if (num_enable[middle]) {
        connection[i][middle] = false;
        connection[middle][i] = false;
        connection[j][middle] = false;
        connection[middle][j] = false;
      } else {
        connection[i][j] = false;
        connection[j][i] = false;
      }
      return;
    }
    if (distance == 2) {
      int minimum = std::min(i, j);
      if (minimum == 0 || minimum == 3 || minimum == 6) {
        int middle = (i + j) / 2;
        if (num_enable[middle]) {
          connection[i][middle] = false;
          connection[middle][i] = false;
          connection[j][middle] = false;
          connection[middle][j] = false;
        }
      } else {
        connection[i][j] = false;
        connection[j][i] = false;
      }
      return;
    }
    connection[i][j] = false;
    connection[j][i] = false;
  }
  bool operator==(const FingerCode& other) {
    for (int i = 0; i < 9; ++i) {
      for (int j = i + 1; j < 9; ++j) {
        if (this->connection[i][j] != other.connection[i][j]) return false;
      }
    }
    return true;
  }
  bool operator<(const FingerCode& other) const {
    for (int i = 0; i < 9; ++i) {
      for (int j = i + 1; j < 9; ++j) {
        if (this->connection[i][j] != other.connection[i][j]) return this->connection[i][j] < other.connection[i][j];
      }
    }
    return false;
  }

  bool empty() {
    for (int i = 0; i < 9; ++i) {
      for (int j = i + 1; j < 9; ++j) {
        if (connection[i][j]) return false;
      }
    }
    return true;
  }
};

void dfs(bool* num_enable, std::set<FingerCode>& codes, FingerCode current_code, std::vector<bool> used, int index,
         int num_used) {
  if (codes.find(current_code) == codes.end()) {
    if (!current_code.empty()) {
      codes.insert(current_code);
    }
  }
  if (num_used == activate_num) return;
  used[index] = true;
  for (int i = 0; i < 9; ++i) {
    if (!used[i] && num_enable[i]) {
      current_code.addConnection(index, i, num_enable);
      dfs(num_enable, codes, current_code, used, i, num_used + 1);
      current_code.removeConnection(index, i, num_enable);
    }
  }
}

ll findSolutions(bool* num_enable) {
  ll res = 0;
  std::set<FingerCode> codes;
  for (int i = 0; i < 9; ++i) {
    if (num_enable[i]) {
      std::vector<bool> used(9, false);
      FingerCode current_code;
      dfs(num_enable, codes, current_code, used, i, 0);
    }
  }
  res = codes.size();
  return res;
}

int main(int argc, char** argv) {
  int T;
  std::cin >> T;
  for (int _t = 0; _t < T; ++_t) {
    activate_num = 0;
    bool num_enable[9] = {false, false, false, false, false, false, false, false, false};
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        char c;
        std::cin >> c;
        if (c == '.') {
          num_enable[i * 3 + j] = true;
          activate_num++;
        }
      }
    }
    std::cout << findSolutions(num_enable) << std::endl;
  }
  return 0;
}