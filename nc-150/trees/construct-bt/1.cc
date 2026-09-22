#include "../tree.h"
#include <unordered_map>
#include <vector>

class Solution {
  int idx = 0;
  std::unordered_map<int, int> map;

  TreeNode *bt(std::vector<int> &preorder, int l, int r) {
    if (l > r)
      return nullptr;
    int mid = map[preorder[idx]];
    TreeNode *root = new TreeNode(preorder[idx++]);
    root->left = bt(preorder, l, mid - 1);
    root->right = bt(preorder, mid + 1, r);
    return root;
  }

public:
  TreeNode *const_bt(std::vector<int> &preorder, std::vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); i++) {
      map[inorder[i]] = i;
    }
    return bt(preorder, 0, inorder.size() - 1);
  }
};
