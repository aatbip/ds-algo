#include "../tree.h"
#include <climits>
#include <queue>
#include <tuple>

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    if (!root)
      return true;
    std::queue<std::tuple<TreeNode *, long, long>> qu;
    qu.push(std::make_tuple(root, LONG_MIN, LONG_MAX));
    while (!qu.empty()) {
      auto [node, leftVal, rightVal] = qu.front();
      qu.pop();
      if (!(leftVal < node->val && rightVal > node->val))
        return false;
      if (node->left)
        qu.push(std::make_tuple(node->left, leftVal, node->val));
      if (node->right)
        qu.push(std::make_tuple(node->right, node->val, rightVal));
    }
    return true;
  }
};
