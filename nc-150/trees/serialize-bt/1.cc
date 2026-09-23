#include "../tree.h"
#include <iostream>
#include <string>

class Codec {
  std::string str;

  int i = 0;

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

  TreeNode *deserialize(std::string buf) {
    if (buf[i] == '-') {
      i++;
      return NULL;
    }
    TreeNode *root = new TreeNode(buf[i++] - '0');
    root->left = deserialize(buf);
    root->right = deserialize(buf);
    return root;
  }
};

int main(void) {
  Codec c;

  TreeNode right(3);
  TreeNode left(2);
  TreeNode root(1, &left, &right);

  std::string buf = c.serialize(&root);
  std::cout << buf << "\n";

  TreeNode *dr = c.deserialize(buf);
  dr->bfs_levelorder();

  return 0;
}
