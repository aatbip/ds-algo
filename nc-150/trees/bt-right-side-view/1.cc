/* Binary Tree Right Side View-
 *You are given the root of a binary tree. Return only the values of the nodes that are visible from the right side of
 * the tree, ordered from top to bottom.
 *
 * Solution- Similar to Binary Tree Level Order Travelsal problem.
 * Time complexity- O(n)
 * Space complexity- O(n), where 'n' is number of nodes
 * */

#include "../tree.h"
#include <queue>
#include <vector>

class Solution {
public:
  std::vector<int> right_size_view(TreeNode *root) {
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
