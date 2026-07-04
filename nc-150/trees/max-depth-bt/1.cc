#include "../tree.h"
#include <iostream>

class Solution {
private:
  int n = 0;
  int max = n;

  int count(TreeNode *node) {
    if (!node) {
      if (max < n) {
        max = n;
        n = 0;
      }
      return max;
    }
    n++;
    count(node->left);
    count(node->right);
    return n + 1;
  }

public:
  int max_depth(TreeNode *root) {
    int n = 0;
    if (!root)
      return n;
    return count(root);
  }
};

int main(void) {
  TreeNode left1(6);
  TreeNode left2(5);
  TreeNode left(3, &left1, &left2);
  TreeNode right(4);
  TreeNode root(2, &left, &right);
  left.bfs_levelorder(&left);
  Solution s;
  std::cout << s.max_depth(&left) << "\n";
  return 0;
}
