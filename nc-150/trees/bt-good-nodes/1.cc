/*Count good notes in binary tree-
 * Within a binary tree, a node x is considered good if the path from the root of the tree to the node x contains
 * no nodes with a value greater than the value of node x.
 * Given the root of a binary tree root, return the number of good nodes within the tree.
 *
 * Solution-
 * Solved using recursive DFS (preorder travelsal).
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 * */

#include "../tree.h"
#include <algorithm>

class Solution {
private:
  int calc(TreeNode *node, int max) {
    if (!node)
      return 0;
    int c = node->val >= max ? 1 : 0;
    max = std::max(max, node->val);
    c += calc(node->left, max);
    c += calc(node->right, max);
    return c;
  }

public:
  int good_nodes(TreeNode *root) { return calc(root, root->val); }
};
