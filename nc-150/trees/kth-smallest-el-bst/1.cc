
#include "../tree.h"
#include <vector>

class Solution {
  std::vector<int> v;

  void inorder(TreeNode *root) {
    if (!root)
      return;
    inorder(root->left);
    v.push_back(root->val);
    inorder(root->right);
  }

public:
  int kth_smallest(TreeNode *root, int k) {
    inorder(root);
    return v[k - 1];
  }
};
