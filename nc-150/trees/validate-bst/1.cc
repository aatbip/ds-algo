#include "../tree.h"

class Solution {
private:
  bool valid_bst(TreeNode *root, TreeNode *left, TreeNode *right) {
    if (!root)
      return true;
    if (!(left->val < root->val && right->val > root->val))
      return false;
    return valid_bst(root->left, root->left->left, root->left->right) &&
           valid_bst(root->right, root->right->left, root->right->right);
  }

public:
  bool isValidBST(TreeNode *root) { return valid_bst(root, root->left, root->right); }
};
