#include <string>
#include <unordered_map>

class TrieNode {
public:
  std::unordered_map<char, TrieNode *> map;
  bool end;
};

class Trie {
  TrieNode *root;

public:
  Trie() { root = new TrieNode(); }

  void insert(std::string word) {
    TrieNode *cur = root;
    for (char c : word) {
      if (cur->map.find(c) == cur->map.end()) {
        cur->map[c] = new TrieNode();
      }
      cur = cur->map[c];
    }
    cur->end = true;
  }
};
