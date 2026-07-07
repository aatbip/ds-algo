/*Given a binary tree, return true if it is height-balanced and false otherwise. A height-balanced binary tree is
 * defined as a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
 *
 * Solution-
 * Solved using recursive DFS(post-order). `check` returns -1 if the subtree is unbalanced, otherwise it returns the
 * height value.
 *
 * Time complexity: O(h), where h = log(n) if balanced and h = n if unbalanced skewed tree.
 * Space complexity: O(n)
 * */

#include "../tree.h"

class Solution {
  int check(TreeNode *node) {
    if (!node)
      return 0;

    int lh = check(node->left);
    if (lh == -1)
      return -1;

    int rh = check(node->right);
    if (rh == -1)
      return -1;

    if (std::abs(lh - rh) > 1)
      return -1;

    return 1 + std::max(lh, rh);
  }

public:
  bool isBalanced(TreeNode *root) {
    int ch = check(root);
    std::cout << ch << "\n";
    return ch != -1;
  }
};

int main(void) {
  TreeNode left(3);
  TreeNode left1(1, &left, nullptr);
  TreeNode root(2, &left1, nullptr);
  root.bfs_levelorder();

  Solution s;
  std::cout << "res: " << s.isBalanced(&root) << "\n";

  return 0;
}
