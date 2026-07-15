#include "../tree.h"
#include <stack>
#include <unordered_set>

class Solution {
public:
  int good_nodes(TreeNode *root) {
    std::unordered_set<int> set;
    std::stack<TreeNode *> stk;
    if (root->left)
      stk.push(root->left);
    if (root->right)
      stk.push(root->right);
    while (!stk.empty()) {
      TreeNode *cur = stk.top();
      stk.pop();
      if (cur->left)
        stk.push(cur->left);
      if (cur->right)
        stk.push(cur->right);
      if (cur->val >= root->val && set.find(cur->val) == set.end()) {
        set.insert(cur->val);
      }
    }
    return set.size() + 1;
  }
};
