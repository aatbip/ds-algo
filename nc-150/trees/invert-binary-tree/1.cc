/*You are given the root of a binary tree root. Invert the binary tree and return its root.
 *
 * Solution-
 * Recursive solution using DFS (preorder travelsal i.e. visit node, left node, right node).
 *
 * Time complexity- O(n)
 * Space complexity- O(n) due to recursive funciton stack frame
 * */

#include "../tree.h"

class Solution {
  TreeNode *invert(TreeNode *node) {
    TreeNode *temp = node->left;
    node->left = node->right;
    node->right = temp;
    return node;
  }

public:
  TreeNode *invert_binary_tree(TreeNode *root) {
    if (!root)
      return nullptr;
    TreeNode *node = invert(root);
    invert_binary_tree(root->left);
    invert_binary_tree(root->right);
    return root;
  }
};
