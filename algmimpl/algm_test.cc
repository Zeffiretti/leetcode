#include <vector>
#include "algmimpl/hashmap.hh"

int main() {
  HashMap<int, int> map;
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  map.resize(v.size());
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v.size(); ++j) {
      map.insert(i, v[j]);
    }
  }
  map.print();
  return 0;
}