#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const* argv[]) {
  int n;
  cin >> n;
  int pre;
  int res = 0;
  cin >> pre;
  for (int i = 1; i < n; ++i) {
    int cur;
    cin >> cur;
    if (cur > pre) {
      res += cur - pre;
    }
  }
  cout << res << endl;
}