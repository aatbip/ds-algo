#include "../tree.h"
#include <unordered_map>
#include <vector>

class Solution {
  int idx = 0;
  std::unordered_map<int, int> map;

public:
  TreeNode *const_bt(std::vector<int> &preorder, std::vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); i++) {
      map[inorder[i]] = i;
    }
  }
};
