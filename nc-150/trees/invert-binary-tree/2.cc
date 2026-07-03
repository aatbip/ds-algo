/*You are given the root of a binary tree root. Invert the binary tree and return its root.
 *
 * Solution-
 * Recursive solution using DFS (preorder travelsal i.e. visit node, left node, right node).
 *
 * Time complexity- O(n)
 * Space complexity- O(n) due to the stack container
 * */

#include "./tree.h"
#include <iostream>
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

int main(void) {
  TreeNode left(3);
  TreeNode right(4);
  TreeNode root(2, &left, &right);
  root.bfs_levelorder(&root);

  return 0;
}
