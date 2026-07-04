/*Given the root of a binary tree, return its depth. The depth of a binary tree is defined as the number of nodes
 * along the longest path from the root node down to the farthest leaf node.
 *
 * Solution:
 * Stack based recursive DFS solution.
 * Time complexity- o(n)
 * Space complexity- O(n)
 * */

#include "../tree.h"
#include <algorithm>
#include <stack>
#include <utility>

class Solution {
public:
  int max_depth(TreeNode *root) {
    int n = 0;
    std::stack<std::pair<TreeNode *, int>> stk;
    stk.push({root, 1});
    while (!stk.empty()) {
      std::pair<TreeNode *, int> cur = stk.top();
      TreeNode *node = cur.first;
      int depth = cur.second;
      stk.pop();

      if (node) {
        n = std::max(n, depth);
        stk.push({node->left, depth + 1});
        stk.push({node->right, depth + 1});
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
  std::cout << "here: " << s.max_depth(&root) << "\n";
  return 0;
}
