#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
    int num_train = 0;
    int n = energy.size();
    int c_energy = initialEnergy;
    int c_experience = initialExperience;
    for (int i = 0; i < n; ++i) {
      if (c_energy <= energy[i]) {
        num_train += energy[i] + 1 - c_energy;
        c_energy = energy[i] + 1;
      }
      if (c_experience <= experience[i]) {
        num_train += experience[i] + 1 - c_experience;
        c_experience = experience[i] + 1;
      }
      c_energy -= energy[i];
      c_experience += experience[i];
    }
    return num_train;
  }
};