#include "./tree.h"

class Solution {
  TreeNode *invert(TreeNode *node) {
    TreeNode *temp = node->left;
    node->left = node->right;
    node->right = temp;
    return node;
  }

  TreeNode *invert_binary_tree(TreeNode *root) {
    if (!root)
      return nullptr;
    TreeNode *node = invert(root);
    invert_binary_tree(root->left);
    invert_binary_tree(root->right);
    return root;
  }
};
