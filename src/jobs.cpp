#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void replace(string &str, string old_st, char new_st) {
  int index = 0;
  while (index < str.size()) {
    if (str[index] == old_st[0]) {
      int i = 0;
      while (i < old_st.size() && str[index + i] == old_st[i]) {
        i++;
      }
      if (i == old_st.size()) {
        str[index] = new_st;
        index += i;
      } else {
        index++;
      }
    } else {
      index++;
    }
  }
}

int main() {
  string str;
  cin >> str;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string old_st;
    cin >> old_st;
    char new_st;
    cin >> new_st;
    replace(str, old_st, new_st);
    cout << "[" << i << "]:" << str << endl;
  }
  cout << str << endl;
  return 0;
}