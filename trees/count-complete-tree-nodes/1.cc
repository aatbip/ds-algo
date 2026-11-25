/*222. Count Complete Tree Nodes-
 *  Given the root of a complete binary tree, return the number of the nodes in the tree.
 *According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all
 *nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
 *Design an algorithm that runs in less than O(n) time complexity.
 *
 * Solution-
 * Solved using recursive approach.
 *
 * Time complexity-
 * For count_left = O(log n) and for count_right = O(log n)
 * = O(log n) + O(log n) = O(2 logn) = O(log n)
 * No. of calls for recursive path: O(log n)
 * So, O(log n) * O(log n) = O(log^2 n)
 *
 *
 * Space complexity- The height of a complete tree (balanced tree) is O(log n). So there will be at most O(log n)
 * recursion stack. Therefore, O(log n)
 *
 */

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
