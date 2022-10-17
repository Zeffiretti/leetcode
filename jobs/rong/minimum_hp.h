#ifndef JOBS_RONG_MINIMUM_HP
#define JOBS_RONG_MINIMUM_HP
#include <iostream>
#include <numeric>
#include <vector>

int mini_required;
int max_required;

void dfs(const std::vector<int> attacks, int index, int hp, int unused, int recover) {
  if (index == attacks.size()) {
    mini_required = std::min(mini_required, max_required - hp);
    return;
  }
  int tmp_hp = hp - attacks[index] + recover;
  if (tmp_hp < 0 && unused == 0) {
    return;
  } else if (tmp_hp < 0) {
    dfs(attacks, index + 1, hp + recover, unused - 1, recover + 1);
  } else {
    if (unused > 0) {
      dfs(attacks, index + 1, hp + recover, unused - 1, recover + 1);
    }
    dfs(attacks, index + 1, tmp_hp, unused, recover);
  }
}

int minimum_hp_required(const std::vector<int> attacks, int k, int recover = 0) {
  if (attacks.size() == 1) {
    return k > 0 ? 0 : attacks[0];
  }
  // assign attacks[1:end] to nxt
  std::vector<int> nxt = std::vector<int>(attacks.begin() + 1, attacks.end());
  if (k == 0) {
    return attacks[0] + minimum_hp_required(nxt, k, recover) - recover;
  } else {
    int res1 = attacks[0] + minimum_hp_required(nxt, k, recover) - recover;
    int res2 = 0 + minimum_hp_required(nxt, k - 1, recover + 1);
    return std::min(res1, res2);
  }
}

#endif /* JOBS_RONG_MINIMUM_HP */
