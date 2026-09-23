#include "../tree.h"
#include <string>

class Codec {
  std::string str;

public:
  std::string serialize(TreeNode *node, std::string d) {
    if (!node) {
      str.append(d);
      str.append("-");
      return str;
    }
    if (d == "")
      str.append(std::to_string(node->val));
    else {
      str.append(d);
      str.append(std::to_string(node->val));
    }
    serialize(node->left, "l");
    serialize(node->right, "r");
    return str;
  }

  TreeNode *deserialize(std::string buf) { return nullptr; }
};

int main(void) {
  Codec c;

  TreeNode right(3);
  TreeNode left(2);
  TreeNode root(1, &left, &right);

  std::cout << c.serialize(&root, "");

  return 0;
}
