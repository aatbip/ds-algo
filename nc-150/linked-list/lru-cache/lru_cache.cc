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
  Node *head;
  Node *tail;

public:
  LRUCache(int c) {
    capacity = c;
    size = 0;
    head = nullptr;
    tail = nullptr;
  }

  void put(int k, int v) {
    if (map.find(k) == map.end()) {
      Node *node = new Node(k, v);
      if (!this->head && !this->tail) { // ie. link is empty
        this->head = node;
        node->next = nullptr;
        this->tail = node;
        node->prev = nullptr;
      } else {
        if (size == capacity) {
          Node *temp = this->head;
          this->head = this->head->next;
          map.erase(temp->key);
          delete (temp);
          this->size--;
        }
        node->prev = tail;
        this->tail->next = node;
        node->next = nullptr;
        this->tail = node;
      }
      map[k] = node;
      this->size++;
    } else {
      Node *p = map.find(k)->second;
      p->val = v;
      this->tail->next = p;
      p->prev = this->tail;
      this->tail = p;
    }
  }

  int get(int k) {
    if (map.find(k) == map.end())
      return -1;
    Node *p = map.find(k)->second;
    this->tail->next = p;
    p->prev = this->tail;
    this->tail = p;
    int val = p->val;
    return val;
  }
};

int main(void) {
  LRUCache *head = new LRUCache(5);
  head->put(1, 100);
  head->put(2, 200);
  head->put(3, 300);
  head->put(4, 400);
  head->put(5, 500);
  head->put(6, 600);
  std::cout << head->get(1) << "\n";
  return 0;
}
