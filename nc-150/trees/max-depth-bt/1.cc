#include "../tree.h"
#include <algorithm>
#include <iostream>

class Solution {

public:
  int max_depth(TreeNode *root) {
    if (!root)
      return 0;
    return 1 + std::max(max_depth(root->left), max_depth(root->right));
  }
};

int main(void) {
  TreeNode left1(6);
  TreeNode left2(5);
  TreeNode left(3, &left1, &left2);
  TreeNode right(4);
  TreeNode root(2, &left, &right);

  Solution s;
  std::cout << s.max_depth(&root) << "\n";
  return 0;
}
