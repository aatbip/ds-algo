#include "../tree.h"
#include <algorithm>
#include <climits>

class Solution {
  int ans = INT_MIN;

  int dfs(TreeNode *node) {
    if (!node)
      return 0;
    int l = dfs(node->left);
    int r = dfs(node->right);
    int res = std::max(l, r) + node->val;
    ans = std::max(ans, node->val + l + r);
    return res;
  }

  int max_path_sum(TreeNode *root) {
    dfs(root);
    return ans;
  }
};
