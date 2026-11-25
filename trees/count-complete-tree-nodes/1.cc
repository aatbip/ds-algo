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
private:
  int count_left(TreeNode *root) {
    int height = 0;
    TreeNode *cur = root;
    while (cur) {
      cur = cur->left;
      height += 1;
    }
    return height;
  }
  int count_right(TreeNode *root) {
    int height = 0;
    TreeNode *cur = root;
    while (cur) {
      cur = cur->right;
      height += 1;
    }
    return height;
  }

public:
  int count_nodes(TreeNode *root) {
    int height = count_left(root);
    if (height == count_right(root)) {
      return (1 << height) - 1;
    }
    return 1 + count_nodes(root->left) + count_nodes(root->right);
  }
};
