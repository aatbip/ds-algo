/*Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
 *
 * LCA definition: The lowest common ancestor is defined between two nodes p and q
 * as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).
 *
 * Time complexity: O(h)
 * Space complexity: O(h)
 * where 'h' -> height of bst
 * */

#include "../tree.h"

class Solution {
public:
  TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root)
      return nullptr;
    if (p->val < root->val && q->val < root->val) {
      return lca(root->left, p, q);
    } else if (p->val > root->val && q->val > root->val) {
      return lca(root->right, p, q);
    }
    return root;
  }
};
