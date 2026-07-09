#include "../tree.h"
#include <stack>
#include <utility>

class Solution {
public:
  bool is_sametree(TreeNode *p, TreeNode *q) {
    std::stack<std::pair<TreeNode *, TreeNode *>> stk;
    stk.push({p, q});
    while (!stk.empty()) {
      auto [node1, node2] = stk.top();
      stk.pop();
      if (!node1 && !node2)
        continue;
      if (!node1 || !node2 || node1->val != node2->val) {
        return false;
      }
      stk.push({node1->right, node2->right});
      stk.push({node1->left, node2->left});
    }
    return true;
  }
};

int main(void) {
  TreeNode al(1);
  TreeNode ar(3);
  TreeNode aroot(2, &al, &ar);

  TreeNode bl(4);
  TreeNode br(3);
  TreeNode broot(2, &bl, &br);

  aroot.bfs_levelorder();
  std::cout << "\n";
  broot.bfs_levelorder();
  std::cout << "\n";

  Solution s;
  std::cout << s.is_sametree(&aroot, &broot) << "\n";

  return 0;
}
