#ifndef JOBS_3IROBOTICS_WATERPROBLEM
#define JOBS_3IROBOTICS_WATERPROBLEM
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

#ifndef INT_MAX
#  define INT_MAX 2147483647
#endif

#define MethodNone 0
#define MethodWell 1
#define MethodPipe 2

class WaterField {
 public:
  WaterField() {
    costs = {{5, 2, 2, 2, 9, 9}, {2, 4, 3, 3, 9, 9}, {2, 3, 4, 4, 9, 9},
             {2, 3, 4, 3, 9, 9}, {9, 9, 9, 9, 1, 9}, {9, 9, 9, 9, 9, 20}};
    costs_used = std::vector<int>(num_wells, INT_MAX);
    water_method = std::vector<int>(num_wells, MethodNone);
  }

  WaterField(int n) : num_wells(n) {
    costs = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
    costs_used = std::vector<int>(num_wells, INT_MAX);
    water_method = std::vector<int>(num_wells, MethodNone);
  }

  void writeCost() {
    for (int i = 0; i < num_wells; ++i) {
      for (int j = 0; j < num_wells; ++j) {
        std::cin >> costs[i][j];
        if (costs[i][j] == 0) {
          costs[i][j] = INT_MAX;
        }
      }
    }
  }

  // get the position of the cheapest well
  int cheapestWell() {
    int cheap_cost = INT_MAX;
    int cheap_index = -1;
    for (int i = 0; i < num_wells; ++i) {
      if (water_method[i] != MethodNone) {
        continue;
      }
      if (costs[i][i] < cheap_cost) {
        cheap_cost = costs[i][i];
        cheap_index = i;
      }
    }
    return cheap_index;
  }

  // calculate the minimum cost to water the fields use prim algorithm
  int minimumWaterCost() {
    int min_cost = 0;
    int k = cheapestWell();
    while (num_watered < num_wells) {
      // dig a well to water the kth field, since it is the cheapest
      water_method[k] = MethodWell;
      std::cout << "the " << k << "th field are welled." << std::endl;
      num_watered++;
      costs_used[k] = costs[k][k];

      for (int i = 0; i < num_wells; ++i) {  // iterate the fields, find those cheap enough to connect with the kth
        if (water_method[i] != MethodNone || i == k || costs[i][k] > costs[i][i]) {
          continue;
        } else {
          bool flag = true;
          for (int j = 0; j < num_wells; ++j) {
            if (i != j && j != k && costs[i][j] < costs[i][k]) {
              flag = false;
              break;
            }
          }
          if (flag && water_method[i] == MethodNone) {
            water_method[i] = MethodPipe;
            std::cout << "the " << i << "th field are connected with the " << k << "th field." << std::endl;
            num_watered++;
            costs_used[i] = costs[i][k];
          }
        }
      }
      k = cheapestWell();
    }
    for (int i = 0; i < num_wells; ++i) {
      min_cost += costs_used[i];
    }
    return min_cost;
  }

 private:
  int num_wells = 6;
  int num_watered = 0;
  std::vector<bool> watered;

  // costs[i][j] refers the cost to build a pipe from i to j if i!=j, otherwise refers to the cost to build a well at i
  std::vector<std::vector<int>> costs;
  std::vector<int> costs_used;
  std::vector<int> water_method;  // 0: none, 1: well, 2: pipe
};

#endif /* JOBS_3IROBOTICS_WATERPROBLEM */
