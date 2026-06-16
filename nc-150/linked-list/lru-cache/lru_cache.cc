#include <iostream>
#include <unordered_map>

class Node {
public:
  Node *next;
  Node *prev;
  int key;
  int val;

  Node(int k, int v) : key{k}, val{v}, next{nullptr}, prev{nullptr} {}
};

class LRUCache {
  int capacity;
  int size;
  std::unordered_map<int, Node *> map;
  Node *head; // sentinel node, that is fixed and eliminate boundary edge cases check
  Node *tail; // sentinel node, that is fixed and eliminate boundary edge cases check

public:
  LRUCache(int c) {
    capacity = c;
    size = 0;
    head = new Node(0, 0); // dummy head
    tail = new Node(0, 0); // dummy tail
    head->next = tail;
    tail->prev = head;
  }

  void unlink_node(Node *n) {
    n->prev->next = n->next;
    n->next->prev = n->prev;
  }

  void move_to_tail(Node *n) {
    Node *last = tail->prev;
    last->next = n;
    n->prev = last;
    n->next = tail;
    tail->prev = n;
  }

  void put(int k, int v) {
    auto it = map.find(k);
    if (it == map.end()) {
      Node *node = new Node(k, v);
      if (size == capacity) {
        Node *temp = head->next;
        unlink_node(temp);
        map.erase(temp->key);
        delete (temp);
        this->size--;
      }
      move_to_tail(node);
      map[k] = node;
      this->size++;
    } else {
      Node *p = it->second;
      p->val = v;
      unlink_node(p);
      move_to_tail(p);
    }
  }

  int get(int k) {
    auto it = map.find(k);
    if (it == map.end())
      return -1;
    Node *p = it->second;
    unlink_node(p);
    move_to_tail(p);
    return p->val;
  }

  ~LRUCache() {
    Node *cur = head;
    while (!cur) {
      delete cur;
      cur = cur->next;
    }
  }
};

int main(void) {
  LRUCache *cache = new LRUCache(5);
  cache->put(1, 100);
  cache->put(2, 200);
  cache->put(3, 300);
  cache->put(4, 400);
  cache->put(5, 500);
  cache->put(6, 500);
  cache->put(7, 500);
  std::cout << cache->get(1) << "\n";
  std::cout << cache->get(7) << "\n";
  delete cache;
  return 0;
}
