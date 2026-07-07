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
