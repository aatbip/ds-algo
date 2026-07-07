#include "../tree.h"
#include <cstdlib>

class Solution {
  int height_bt(TreeNode *node) {
    if (!node)
      return 0;
    return 1 + std::max(height_bt(node->left), height_bt(node->right));
  }

public:
  bool is_balanced_bt(TreeNode *root) {
    if (!root)
      return true;

    int lh = height_bt(root->left);
    int rh = height_bt(root->right);

    if (std::abs(lh - rh) > 1)
      return false;

    return is_balanced_bt(root->left) & is_balanced_bt(root->right);
  }
};

int main(void) {
  TreeNode left1(6);
  TreeNode left2(5);
  TreeNode left(3, &left1, &left2);
  TreeNode right(4);
  TreeNode root(2, &left, &right);
  root.bfs_levelorder();

  Solution s;
  std::cout << s.is_balanced_bt(&root) << "\n";

  return 0;
}
