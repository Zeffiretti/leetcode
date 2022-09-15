#ifndef JOBS_MOMENTA_COMMONNODE
#define JOBS_MOMENTA_COMMONNODE
#include <iostream>
#include <vector>

struct Node {
  Node* left;
  Node* right;
  int val;
  Node() : left(nullptr), right(nullptr), val(0) {}
  Node(int x) : left(nullptr), right(nullptr), val(x) {}
  Node(int x, Node* left, Node* right) : left(left), right(right), val(x) {}
};

bool dfs(Node* root, Node* target, std::vector<Node*>& path) {
  if (root == nullptr) {
    return false;
  }
  path.push_back(root);
  if (root == target) {
    return true;
  }
  bool found = false;
  found = dfs(root->left, target, path);
  if (found) {
    return true;
  }
  path.pop_back();
  return dfs(root->right, target, path);
}

Node* commonNode(Node* root, Node* p, Node* q) {
  //
  std::vector<Node*> path_to_p;
  if (!dfs(root, p, path_to_p)) {
    std::cout << "q not found" << std::endl;
    return nullptr;
  }
  std::cout << "path to p: ";
  for (auto node : path_to_p) {
    std::cout << node->val << " ";
  }
  std::cout << std::endl;
  std::vector<Node*> path_to_q;
  if (!dfs(root, q, path_to_q)) {
    std::cout << "p not found" << std::endl;
    return nullptr;
  }
  std::cout << "path to q: ";
  for (auto node : path_to_q) {
    std::cout << node->val << " ";
  }
  std::cout << std::endl;
  size_t i = 1;  // the first node is root, for both
  while (i < path_to_p.size() && i < path_to_q.size()) {
    if (path_to_p[i] == path_to_q[i]) {
      ++i;
    } else {
      return path_to_p[i - 1];
    }
  }
  if (i == path_to_p.size()) {
    return path_to_p.back();
  }
  return path_to_q.back();
}

#endif /* JOBS_MOMENTA_COMMONNODE */
