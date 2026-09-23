/* Binary tree maximum path sum- Given the root of a non-empty binary tree, return the maximum path sum of any non-empty
 * path.
 * A path in a binary tree is a sequence of nodes where each pair of adjacent nodes has an edge connecting them.
 * A node can not appear in the sequence more than once. The path does not necessarily need to include the root. The
 * path sum of a path is the sum of the node's values in the path.
 *
 * Solution - Solved using recursive DFS (postorder traversal).
 * Time complexity - O(n)
 * Space complexity- O(n)
 * */

#include "../tree.h"
#include <algorithm>
#include <climits>

class Solution {
  int ans = INT_MIN;

  int dfs(TreeNode *node) {
    if (!node)
      return 0;
    int l = std::max(dfs(node->left), 0); // std::max to get 0 if negative node value
    int r = std::max(dfs(node->right), 0);
    int res = std::max(l, r) + node->val;
    ans = std::max(ans, node->val + l + r);
    return res;
  }

  int max_path_sum(TreeNode *root) {
    dfs(root);
    return ans;
  }
};
