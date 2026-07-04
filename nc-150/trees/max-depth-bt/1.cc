/*Given the root of a binary tree, return its depth. The depth of a binary tree is defined as the number of nodes
 * along the longest path from the root node down to the farthest leaf node.
 *
 * Solution:
 * Solved using recursion.
 * Time complexity- o(n)
 * Space complexity- O(h), where h = log(n) in best case (if tree is balanced) while h = n in worst case (if tree is
 * unbalanced). This is because, when max_depth is resolved, the stack frame gets created and gets unwinded when
 * max_depth returns. If the tree is balanced then the left subtree and right subtree of every node is balanced making
 * the stack frame to unwind sooner using only log(n) space.
 * */

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
  root.bfs_levelorder();

  Solution s;
  std::cout << s.max_depth(&root) << "\n";
  return 0;
}
