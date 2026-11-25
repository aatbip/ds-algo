class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  int count_nodes(TreeNode *root) {
    int lh = 0, rh = 0;
    TreeNode *cur = root;
    while (cur) {
      cur = cur->left;
      lh += 1;
    }
    cur = root;
    while (cur) {
      cur = cur->right;
      rh += 1;
    }
    if (lh == rh) { // perfect binary tree
      return (1 << lh) - 1;
    }
    return 1 + count_nodes(root->left) + count_nodes(root->right);
  }
};
