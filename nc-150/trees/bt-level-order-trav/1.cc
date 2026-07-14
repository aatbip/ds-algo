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

int main(void) { return 0; }
