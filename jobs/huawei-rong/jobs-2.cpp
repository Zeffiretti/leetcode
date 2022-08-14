#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define UNUSED(x) (void)(x)

int main(int argc, char const* argv[]) {
  UNUSED(argc);
  UNUSED(argv);
  int n;
  cin >> n;
  vector<int> f(n + 1);
  for (int i = 1; i <= n; i++) {
    int minn = 10000;
    for (int j = 1; j * j <= i; j++) {
      minn = min(minn, f[i - j * j]);
      if (j * j * j <= i) {
        minn = min(minn, f[i - j * j * j]);
      }
    }
    f[i] = minn + 1;
  }
  cout << f[n] << endl;
}
