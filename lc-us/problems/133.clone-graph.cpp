/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */
#include "utils.h"
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
 public:
  Node *cloneGraph(Node *node) {
    if (!node) return nullptr;
    unordered_map<Node *, Node *> map;
    return dfs(node, map);
  }
  Node *dfs(Node *node, unordered_map<Node *, Node *> &map) {
    if (!node) return nullptr;
    if (map.find(node) != map.end()) return nullptr;
    Node *new_node = new Node(node->val);
    map[node] = new_node;
    for (auto neighbor : node->neighbors) {
      dfs(neighbor, map);
      new_node->neighbors.push_back(map[neighbor]);
    }
    return new_node;
  }
};
// @lc code=end

