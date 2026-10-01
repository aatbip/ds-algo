#include <unordered_map>

class TrieNode {
  std::unordered_map<char, TrieNode *> map;
  bool end;
};

class Trie {
  TrieNode *root;

public:
  Trie() { root = new TrieNode(); }
};
