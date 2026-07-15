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
