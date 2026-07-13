/*Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
 *
 * LCA definition: The lowest common ancestor is defined between two nodes p and q
 * as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).
 *
 * Time complexity: O(h)
 * Space complexity: O(1)
 * where 'h' -> height of bst
 * */

#include "../tree.h"

class Solution {
public:
  TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q) {
    TreeNode *cur = root;
    while (cur) {
      if (p->val < cur->val && q->val < cur->val) {
        cur = cur->left;
      } else if (p->val > cur->val && q->val > cur->val) {
        cur = cur->right;
      } else {
        return cur;
      }
    }
    return nullptr;
  }
};
