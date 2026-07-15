#include "../tree.h"
#include <queue>
#include <vector>

class Solution {
public:
  std::vector<int> right_size_view(TreeNode *root) {
    if (!root)
      return {};
    std::vector<std::vector<int>> vec;
    std::queue<TreeNode *> qu;
    qu.push(root);
    std::vector<int> out;
    while (!qu.empty()) {
      int size = qu.size();
      TreeNode *res = nullptr;
      for (int i = 0; i < size; i++) {
        TreeNode *cur = qu.front();
        qu.pop();
        if (cur) {
          qu.push(cur->left);
          qu.push(cur->right);
          res = cur;
        }
      }
      if (res) {
        out.push_back(res->val);
      }
    }
    return out;
  }
};
