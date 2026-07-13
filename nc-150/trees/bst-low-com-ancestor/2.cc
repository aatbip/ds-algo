#include "../tree.h"
#include <stack>
class Solution {
public:
  TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q) {
    std::stack<TreeNode *> stk;
    if (!root)
      return NULL;
    stk.push(root);
    TreeNode *cur;
    while (!stk.empty()) {
      cur = stk.top();
      stk.pop();
      if (p->val < cur->val && q->val < cur->val) {
        stk.push(cur->left);
      } else if (p->val > cur->val && q->val > cur->val) {
        stk.push(cur->right);
      }
    }
    return cur;
  }
};
