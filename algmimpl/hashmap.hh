#ifndef MYALGORITHM_HASHMAP
#define MYALGORITHM_HASHMAP

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

template <typename index_type, typename value_type>
class HashMap {
 public:
  HashMap() {}
  ~HashMap() {}
  void insert(index_type index, value_type value) {
    if (index >= capacity_) {
      resize(index + 1);
    }
    if (data_[index] == nullptr) {
      data_[index] = new value_type(value);
      ++size_;
    } else {
      *data_[index] = value;
    }
  }
  value_type* find(index_type index) {
    if (index >= capacity_) {
      return nullptr;
    }
    return data_[index];
  }
  void erase(index_type index) {
    if (index >= capacity_) {
      return;
    }
    if (data_[index] != nullptr) {
      delete data_[index];
      data_[index] = nullptr;
      --size_;
    }
  }
  void clear() {
    for (int i = 0; i < capacity_; ++i) {
      if (data_[i] != nullptr) {
        delete data_[i];
        data_[i] = nullptr;
      }
    }
    size_ = 0;
  }
  int size() { return size_; }
  int capacity() { return capacity_; }
  void resize(int capacity) {
    if (capacity <= capacity_) {
      return;
    }
    capacity_ = capacity;
    data_.resize(capacity_);
  }
  void print() {
    for (int i = 0; i < capacity_; ++i) {
      if (data_[i] != nullptr) {
        std::cout << i << ": " << *data_[i] << std::endl;
      }
    }
  }

 private:
  std::vector<value_type*> data_;
  int size_ = 0;
  int capacity_ = 0;
};
#endif /* MYALGORITHM_HASHMAP */
