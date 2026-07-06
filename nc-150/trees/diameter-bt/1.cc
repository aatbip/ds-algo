
#include "../tree.h"
#include <algorithm>
#include <iostream>

class Solution {
  int diameter = 0;

  int height(TreeNode *root) {
    if (!root)
      return 0;
    int left_height = height(root->left);
    int right_height = height(root->right);
    diameter = std::max(diameter, left_height + right_height);
    return 1 + std::max(left_height, right_height);
  }

public:
  int diameterOfBinaryTree(TreeNode *root) {
    diameter = 0;
    height(root);
    return diameter;
  }
};

int main(void) {
  TreeNode left1(6);
  TreeNode left2(5);
  TreeNode left(3, &left1, &left2);
  TreeNode right(4);
  TreeNode root(2, &left, &right);
  Solution s;
  std::cout << s.diameterOfBinaryTree(&root) << "\n";
  return 0;
}
