#include "../tree.h"
#include <queue>

class Solution {
public:
  int max_depth(TreeNode *root) {
    int n = 0;
    std::queue<TreeNode *> qu;
    qu.push(root);
    while (!qu.empty()) {
      int size = qu.size();
      n++;
      for (int i = 0; i < size; i++) {
        TreeNode *node = qu.front();
        qu.pop();
        if (node->left)
          qu.push(node->left);
        if (node->right)
          qu.push(node->right);
      }
    }
    return n;
  }
};

int main(void) {
  TreeNode left1(6);
  TreeNode left2(5);
  TreeNode left(3, &left1, &left2);
  TreeNode right(4);
  TreeNode root(2, &left, &right);
  root.bfs_levelorder();

  Solution s;
  std::cout << s.max_depth(&root) << "\n";
  return 0;
}
