#include <unordered_map>

class Node {
  Node *next;
  Node *prev;
  int key;
  int val;

public:
  Node(int k, int v) : key{k}, val{v}, next{nullptr}, prev{nullptr} {}
};

class LRUCache {
  int capacity;
  int size;
  std::unordered_map<int, LRUCache *> map;
  Node *head;

public:
  LRUCache(int c) {
    capacity = c;
    size = 0;
    head = nullptr;
  }
};

int main(void) {
  LRUCache *head = new LRUCache(20);
  return 0;
}
