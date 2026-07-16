#include "../tree.h"
#include <climits>

class Solution {
private:
  bool valid_bst(TreeNode *node, long leftVal, long rightVal) {
    if (!node)
      return true;
    if (!(leftVal < node->val && rightVal > node->val))
      return false;
    return valid_bst(node->left, leftVal, node->val) && valid_bst(node->right, node->val, rightVal);
  }

public:
  bool isValidBST(TreeNode *root) { return valid_bst(root, LONG_MIN, LONG_MAX); }
};
