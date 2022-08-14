#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

class FoodRatings {
 public:
  struct Food {
    string name;
    string cuisine;
    int rating;
    bool removed;
    bool operator<(const Food& other) const {
      if (rating == other.rating) {
        return name < other.name;
      } else {
        return rating < other.rating;
      }
    }
    Food(string name, string cuision, int rating, bool removed)
        : name(name), cuisine(cuisine), rating(rating), removed(removed) {}
  };
  map<string, vector<Food*>> ratings_;
  map<string, Food*> map_;

  FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
    for (int i = 0; i < foods.size(); i++) {
      string name = foods[i];
      string cuisine = cuisines[i];
      int rating = ratings[i];
      Food* f = new Food(name, cuisine, rating, false);
      vector<Food*>& v = ratings_[cuisine];
      // push f at the position such that the vector is sorted
      int index = 0;
      while (index < v.size() && v[index] < f) {
        index++;
      }
      v.insert(v.begin() + index, f);
      map_[name] = f;
    }
    cout << "FoodRatings" << endl;
  }

  void changeRating(string food, int newRating) {
    Food* it = map_[food];
    if (it->rating == newRating) {
      return;
    }
    string cuisine = it->cuisine;
    vector<Food*>& v = ratings_[cuisine];
    int index = 0;
    while (index < v.size() && v[index] < it) {
      index++;
    }
    v.erase(v.begin() + index);
    it->rating = newRating;
    index = 0;
    while (index < v.size() && v[index] < it) {
      index++;
    }
    v.insert(v.begin() + index, it);
  }

  string highestRated(string cuisine) {
    vector<Food*>& v = ratings_[cuisine];
    if (v.empty()) {
      return "";
    }
    return v[0]->name;
  }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */