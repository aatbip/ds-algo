#include "../tree.h"
#include <stack>
#include <utility>

class Solution {
private:
  bool is_sameTree(TreeNode *a, TreeNode *b) {
    std::stack<std::pair<TreeNode *, TreeNode *>> stk;
    stk.push({a, b});
    while (!stk.empty()) {
      auto [node1, node2] = stk.top();
      stk.pop();
      if (!node1 && !node2)
        continue;
      if (!node1 || !node2 || node1->val != node2->val)
        return false;
      stk.push({node1->right, node2->right});
      stk.push({node1->left, node2->left});
    }
    return true;
  }

public:
  bool subtree_ispresent(TreeNode *root, TreeNode *subRoot) {
    if (!root || !subRoot)
      return false;
    if (is_sameTree(root, subRoot))
      return true;
    if (subtree_ispresent(root->left, subRoot))
      return true;
    if (subtree_ispresent(root->right, subRoot))
      return true;
    return false;
  }

  bool s(TreeNode *root, TreeNode *subRoot) {
    return (subtree_ispresent(root->left, subRoot) || subtree_ispresent(root->right, subRoot));
  }
};
