#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>
class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

  void bfs_levelorder(TreeNode *root) {
    std::queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty()) {
      TreeNode *node = queue.front();
      std::cout << node->val << "\n";
      queue.pop();
      queue.push(root->left);
      queue.push(root->right);
    }
  }
};

#endif
