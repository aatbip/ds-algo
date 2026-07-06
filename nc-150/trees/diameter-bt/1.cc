/*The diameter of a binary tree is defined as the length of the longest path between any two nodes within the tree.
 * The path does not necessarily have to pass through the root. The length of a path between two nodes in a binary tree
 * is the number of edges between the nodes. Note that the path can not include the same node twice.
 *
 * Given the root of a binary tree root, return the diameter of the tree.
 *
 * Solution-
 * Measure the height of left subtree and right subtree for each node. The sum of the height of left subtree and right
 * subtree for each node is the diameter through that node. Calculate this for every node and return the highest
 * diameter.
 *
 * Time complexity: O(n)
 * Space complexity: O(h), where h=log(n) if tree is balanced otherwise h=n for worst case unbalanced tree
 * */

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
