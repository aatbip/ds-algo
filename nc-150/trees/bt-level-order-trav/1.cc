#include "../tree.h"
#include <queue>
#include <vector>

typedef std::vector<std::vector<int>> list;

class Solution {
public:
  list btl(TreeNode *root) {
    list out;
    std::queue<TreeNode *> qu;
    qu.push(root);
    while (!qu.empty()) {
      std::vector<int> res;
      for (int i = 0; i < qu.size(); i++) {
        TreeNode *cur = qu.front();
        if (!cur)
          break;
        qu.push(cur->left);
        qu.push(cur->right);
        res.push_back(cur->val);
        qu.pop();
      }
      out.push_back(res);
    }
    return out;
  }
};

int main(void) {
  TreeNode ll2(7);
  TreeNode lr2(11);
  TreeNode ll1(10, &ll2, &lr2);

  TreeNode rl2(18);
  TreeNode rr2(26);
  TreeNode rr1(25, &rl2, &rr2);

  TreeNode root(13, &ll1, &rr1);

  root.bfs_levelorder();

  return 0;
}
