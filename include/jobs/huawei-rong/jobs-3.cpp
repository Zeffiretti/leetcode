#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, char const* argv[]) {
  int n;
  cin >> n;
  vector<string> cards;
  vector<int> letters(26, 0);
  for (int i = 0; i < n; ++i) {
    string card;
    cin >> card;
    cards.push_back(card);
    for (char c : card) {
      letters[c - 'a']++;
    }
  }
  vector<int> requir;
  for (int i = 0; i < n; ++i) {
    int req;
    cin >> req;
    requir.push_back(req);
  }
  // descending sort the cards by the length of the card
  sort(cards.begin(), cards.end(), [](const string& a, const string& b) { return a.size() > b.size(); });
  int res = 0;
  for (string card : cards) {
    if (card.size() < 4) {
      res += 10;
      continue;
    }
    int useful_letters = 0;
    for (auto ch : card) {
      if (letters[ch - 'a'] > 0) {
        useful_letters++;
        letters[ch - 'a']--;
      }
    }
    if (useful_letters < 4) {
      res += 10;
      continue;
    }
    res += 3 * useful_letters;
  }
  cout << res << endl;
}
