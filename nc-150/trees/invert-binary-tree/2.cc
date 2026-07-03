#include "./tree.h"
#include <stack>
#include <utility>

class Solution {
  TreeNode *invert_binary_tree(TreeNode *root) {
    if (!root)
      return nullptr;
    std::stack<TreeNode *> stack;
    stack.push(root);
    while (!stack.empty()) {
      TreeNode *node = stack.top();
      std::swap(node->right, node->left);
      stack.pop();
      if (node->left)
        stack.push(node->left);
      if (node->right)
        stack.push(node->right);
    }
    return root;
  }
};
