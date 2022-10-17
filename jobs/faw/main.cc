#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define UNUSED(X) (void)(X)

int main(int argc, char** argv) {
  UNUSED(argc);
  UNUSED(argv);
  int num_stu;
  std::cin >> num_stu;
  int score_asending;
  std::cin >> score_asending;
  // if score_asending == 1, then the score is asending
  std::map<int, std::vector<std::string>> scores;
  for (int i = 0; i < num_stu; ++i) {
    std::string name;
    int score;
    std::cin >> name >> score;
    scores[score].push_back(name);
  }
  if (score_asending == 1) {
    for (auto it = scores.begin(); it != scores.end(); ++it) {
      for (auto name : it->second) {
        std::cout << name << " " << it->first << std::endl;
      }
    }
  } else {
    for (auto it = scores.rbegin(); it != scores.rend(); ++it) {
      for (auto name : it->second) {
        std::cout << name << " " << it->first << std::endl;
      }
    }
  }
  return 0;
}