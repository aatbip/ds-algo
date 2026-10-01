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

  bool search(std::string word) {
    TrieNode *cur = root;
    for (char c : word) {
      if (cur->map.find(c) != cur->map.end()) {
        cur = cur->map[c];
        if (cur->end)
          return true;
      }
    }
    return false;
  }

  bool startsWith(std::string prefix) {
    TrieNode *cur = root;
    for (char c : prefix) {
      if (cur->map.find(c) == cur->map.end())
        return false;
      cur = cur->map[c];
    }
    return true;
  }
};
