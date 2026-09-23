#include "../tree.h"
#include <iostream>
#include <string>

class Codec {
  std::string str;

  int i = 0;

public:
  std::string serialize(TreeNode *node) {
    if (!node) {
      str.append("N");
      return str;
    }
    str.append(std::to_string(node->val));
    str.append("#");
    serialize(node->left);
    serialize(node->right);
    return str;
  }

  TreeNode *deserialize(std::string buf) {
    if (buf[i] == 'N') {
      i++;
      return NULL;
    }

    std::string num;
    while (buf[i] != '#') {
      num += buf[i++];
    }
    i++;
    TreeNode *root = new TreeNode(std::stoi(num));
    root->left = deserialize(buf);
    root->right = deserialize(buf);
    return root;
  }
};

int main(void) {
  Codec c;

  TreeNode right(22);
  TreeNode left(21);
  TreeNode root(20, &left, &right);

  std::string buf = c.serialize(&root);
  std::cout << buf << "\n";

  TreeNode *dr = c.deserialize(buf);
  dr->bfs_levelorder();

  return 0;
}
