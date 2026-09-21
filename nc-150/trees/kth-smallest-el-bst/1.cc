/* Kth Smallest Element In a Bst
 *Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) in the tree.
 *
 * Solution:
 * Solved using recursive inorder traversal (DFS) based solution. Inorder traversal makes it possible to attain
 * elements in the increasing order from the tree. The elements is stored in the vector then kth smallest
 * is returned.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 * */

#include "../tree.h"
#include <vector>

class Solution {
  std::vector<int> v;

  void inorder(TreeNode *root) {
    if (!root)
      return;
    inorder(root->left);
    v.push_back(root->val);
    inorder(root->right);
  }

public:
  int kth_smallest(TreeNode *root, int k) {
    inorder(root);
    return v[k - 1];
  }
};
