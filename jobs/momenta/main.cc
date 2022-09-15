#include <iostream>
#include <vector>

#include "jobs/momenta/commonnode.h"
#include "jobs/momenta/mergearray.h"

#define UNUSED(X) (void)(X)

int main(int argc, char** argv) {
  UNUSED(argc);
  UNUSED(argv);
  std::vector<std::vector<int>> arrays = {{6, 5, 4, 3, 2, 1}, {4, 3, 2}, {5, 4, 3}};
  std::vector<int> result = mergeArray(arrays);
  for (int i : result) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  Node* root = new Node(0);
  // generate the tree, depth = 5
  Node* p = new Node(1);
  Node* q = new Node(2);
  root->left = p;
  root->right = q;
  Node* p1 = new Node(3);
  Node* q1 = new Node(4);
  p->left = p1;
  p->right = q1;
  Node* p2 = new Node(5);
  Node* q2 = new Node(6);
  q->left = p2;
  q->right = q2;
  Node* p3 = new Node(7);
  Node* q3 = new Node(8);
  p1->left = p3;
  p1->right = q3;
  Node* p4 = new Node(9);
  Node* q4 = new Node(10);
  q1->left = p4;
  q1->right = q4;
  Node* p5 = new Node(11);
  Node* q5 = new Node(12);
  p2->left = p5;
  p2->right = q5;
  Node* p6 = new Node(13);
  Node* q6 = new Node(14);
  q2->left = p6;
  q2->right = q6;
  Node* p7 = new Node(15);
  Node* q7 = new Node(16);
  p3->left = p7;
  p3->right = q7;
  Node* p8 = new Node(17);
  Node* q8 = new Node(18);
  q3->left = p8;
  q3->right = q8;
  Node* p9 = new Node(19);
  Node* q9 = new Node(20);
  p4->left = p9;
  p4->right = q9;
  Node* p10 = new Node(21);
  Node* q10 = new Node(22);
  q4->left = p10;
  q4->right = q10;

  Node* parent = commonNode(root, p8, q8);
  std::cout << parent->val << std::endl;

  return 0;
}