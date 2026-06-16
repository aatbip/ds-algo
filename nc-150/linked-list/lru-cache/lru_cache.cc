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
    head = new Node(0, 0); // dummy head
    tail = new Node(0, 0); // dummy tail
  }

  void unlink_node(Node *n) {
    if (n->prev)
      n->prev->next = n->next;
    else
      this->head = n->next;

    if (n->next)
      n->next->prev = n->prev;
    else
      this->tail = n->prev;
  }

  void move_to_tail(Node *n) {
    n->prev = this->tail;
    this->tail->next = n;
    n->next = nullptr;
    this->tail = n;
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
          unlink_node(temp);
          map.erase(temp->key);
          delete (temp);
          this->size--;
        }
        move_to_tail(node);
      }
      map[k] = node;
      this->size++;
    } else {
      Node *p = map.find(k)->second;
      p->val = v;
      unlink_node(p);
      move_to_tail(p);
    }
  }

  int get(int k) {
    if (map.find(k) == map.end())
      return -1;
    Node *p = map.find(k)->second;
    unlink_node(p);
    move_to_tail(p);
    return p->val;
  }
};

int main(void) {
  LRUCache *head = new LRUCache(5);
  head->put(1, 100);
  head->put(2, 200);
  head->put(3, 300);
  head->put(4, 400);
  head->put(5, 500);
  std::cout << head->get(1) << "\n";
  return 0;
}
