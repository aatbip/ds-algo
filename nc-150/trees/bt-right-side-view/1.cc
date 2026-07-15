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
    while (!qu.empty()) {
      int size = qu.size();
      std::vector<int> temp_vec;
      for (int i = 0; i < size; i++) {
        TreeNode *cur = qu.front();
        qu.pop();
        if (cur->left)
          qu.push(cur->left);
        if (cur->right)
          qu.push(cur->right);
        temp_vec.push_back(cur->val);
      }
      vec.push_back(temp_vec);
    }
    std::vector<int> out;
    for (int i = 0; i < vec.size(); i++) {
      out.push_back(vec[i][vec[i].size() - 1]);
    }
    return out;
  }
};
