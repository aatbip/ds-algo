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
