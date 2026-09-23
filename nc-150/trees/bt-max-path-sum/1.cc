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
