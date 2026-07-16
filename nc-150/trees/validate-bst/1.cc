/*Validate BST-
 * Given the root of a binary tree, return true if it is a valid binary search tree, otherwise return false.
 *
 * Solution-
 * Solved using recursive DFS (preorder travelsal).
 * Time complexity: O(n)
 * Space complexity: O(n)
 **/

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
