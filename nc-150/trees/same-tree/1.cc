#include "../tree.h"
#include <stack>

class Solution {
public:
  bool is_sametree(TreeNode *p, TreeNode *q) {
    if (!p || !q)
      return false;
    std::stack<TreeNode *> sta;
    std::stack<TreeNode *> stb;
    sta.push(p);
    stb.push(q);
    while (!sta.empty() || !stb.empty()) {
      TreeNode *ta = sta.top();
      TreeNode *tb = stb.top();
      if (!ta || !tb)
        return false;
      if (ta->val != tb->val) {
        return false;
      }
      sta.pop();
      stb.pop();
      sta.push(ta->right);
      sta.push(ta->left);
      stb.push(tb->right);
      stb.push(tb->left);
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
