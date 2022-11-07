#include <iostream>
#include <vector>

#define UNUSED(X) (void)(X)
int longestCommonSubstring(const std::string& s1, const std::string& s2) {
  if (s1.empty() || s2.empty()) {
    return 0;
  }
  int m = s1.size(), n = s2.size();
  std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s1[i] == s2[j]) {
        dp[i + 1][j + 1] = 1 + dp[i][j];
      } else {
        dp[i + 1][j + 1] = std::max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
  }
  return dp[m][n];
}

struct Node {
  int val;
  Node* next;
};

Node* lastKthNode(Node* head, int k) {
  if (head == nullptr || k <= 0) {
    return nullptr;
  }
  Node* p1 = head;
  Node* p2 = head;
  for (int i = 0; i < k - 1; ++i) {
    if (p2->next != nullptr) {
      p2 = p2->next;
    } else {
      return nullptr;
    }
  }
  while (p2->next != nullptr) {
    p1 = p1->next;
    p2 = p2->next;
  }
  return p1;
}

template <typename T>
class SharedPointer {
 public:
  SharedPointer(T* ptr = nullptr) : ptr_(ptr), count_(new size_t(1)) {}
  SharedPointer(const SharedPointer& other) : ptr_(other.ptr_), count_(other.count_) { ++(*count_); }
  SharedPointer& operator=(const SharedPointer& other) {
    if (this != &other) {
      if (--(*count_) == 0) {
        delete ptr_;
        delete count_;
      }
      ptr_ = other.ptr_;
      count_ = other.count_;
      ++(*count_);
    }
    return *this;
  }
  ~SharedPointer() {
    if (--(*count_) == 0) {
      delete ptr_;
      delete count_;
    }
  }
  T& operator*() const { return *ptr_; }
  T* operator->() const { return ptr_; }
  size_t use_count() const { return *count_; }
  T* get() const { return ptr_; }
  void swap(SharedPointer& other) {
    std::swap(ptr_, other.ptr_);
    std::swap(count_, other.count_);
  }
  bool unique() const { return *count_ == 1; }

 private:
  T* ptr_;
  size_t* count_;
};

int main(int argc, char** argv) {
  UNUSED(argc);
  UNUSED(argv);
  return 0;
}