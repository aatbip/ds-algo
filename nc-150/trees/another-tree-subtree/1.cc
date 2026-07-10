/*Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with
 * the same structure and node values of subRoot and false otherwise. A subtree of a binary tree tree is
 * a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be
 * considered as a subtree of itself.
 *
 * Solution-
 * Solved by checking `is_sameTree` for each node in the main tree (root) and another tree (subRoot). Iterative
 * preorder DFS is used to travel through each node of the main tree.
 *
 * Time complexity: O(n*m),
 * where 'n' is the number of nodes in the main tree and 'm' is number of nodes in subtree. Reason- `subtree_ispresent`
 * visits each node of the main tree and `is_sameTree` visits each node of subtree again.
 *
 * Space complexity: O(n+m)
 * */

#include "../tree.h"
#include <stack>
#include <utility>

class Solution {
private:
  bool is_sameTree(TreeNode *a, TreeNode *b) {
    std::stack<std::pair<TreeNode *, TreeNode *>> stk;
    stk.push({a, b});
    while (!stk.empty()) {
      auto [node1, node2] = stk.top();
      stk.pop();
      if (!node1 && !node2)
        continue;
      if (!node1 || !node2 || node1->val != node2->val)
        return false;
      stk.push({node1->right, node2->right});
      stk.push({node1->left, node2->left});
    }
    return true;
  }

public:
  bool subtree_ispresent(TreeNode *root, TreeNode *subRoot) {
    if (!subRoot)
      return true;
    if (!root)
      return false;

    if (is_sameTree(root, subRoot))
      return true;

    return subtree_ispresent(root->left, subRoot) || subtree_ispresent(root->right, subRoot);
  }
};
