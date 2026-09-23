#include "../tree.h"
#include <string>

class Codec {
  std::string str;

public:
  std::string serialize(TreeNode *node) {
    if (!node) {
      str.append("-");
      return str;
    }
    str.append(std::to_string(node->val));
    serialize(node->left);
    serialize(node->right);
    return str;
  }

  TreeNode *deserialize(std::string buf) {}
};

int main(void) {
  Codec c;

  TreeNode right(3);
  TreeNode left(2);
  TreeNode root(1, &left, &right);

  std::string buf = c.serialize(&root);
  std::cout << buf.front();
  std::cout << buf.back();
  buf.pop_back();
  std::cout << buf.back();
  buf.pop_back();
  std::cout << buf.back();

  return 0;
}
