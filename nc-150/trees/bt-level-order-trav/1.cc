#include "../tree.h"
#include <queue>
#include <vector>

typedef std::vector<std::vector<int>> list;

class Solution {
public:
  list btl(TreeNode *root) {
    list out;
    std::queue<TreeNode *> qu;
    if (root)
      qu.push(root);
    while (!qu.empty()) {
      std::vector<int> res;
      int size = qu.size();
      for (int i = 0; i < size; i++) {
        TreeNode *cur = qu.front();
        res.push_back(cur->val);
        qu.pop();
        if (cur->left)
          qu.push(cur->left);
        if (cur->right)
          qu.push(cur->right);
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

  Solution s;
  list res = s.btl(&root);
  for (auto &i : res) {
    std::cout << '[';
    for (auto &j : i) {
      std::cout << j << " ";
    }
    std::cout << ']';
  }

  return 0;
}
