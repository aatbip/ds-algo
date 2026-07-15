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
