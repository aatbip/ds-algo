/*Count good notes in binary tree-
 * Within a binary tree, a node x is considered good if the path from the root of the tree to the node x contains
 * no nodes with a value greater than the value of node x.
 * Given the root of a binary tree root, return the number of good nodes within the tree.
 *
 * Solution-
 * Solved using iterative DFS (preorder travelsal).
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 * */

#include "../tree.h"
#include <algorithm>
#include <climits>
#include <stack>
#include <utility>

class Solution {
public:
  int good_nodes(TreeNode *root) {
    if (!root)
      return 0;
    int count = 0;
    std::stack<std::pair<TreeNode *, int>> stk;
    stk.push({root, -INT_MAX});
    while (!stk.empty()) {
      auto [node, max] = stk.top();
      stk.pop();
      if (node->val >= max)
        count++;
      max = std::max(max, node->val);
      if (node->right)
        stk.push({node->right, max});
      if (node->left)
        stk.push({node->left, max});
    }
    return count;
  }
};
