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
    if (map.find(k) == map.end()) {
      Node *node = new Node(k, v);
      if (size == capacity) {
        Node *temp = this->head;
        unlink_node(temp);
        map.erase(temp->key);
        delete (temp);
        this->size--;
      }
      move_to_tail(node);
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
  head->put(6, 500);
  head->put(7, 500);
  std::cout << head->get(1) << "\n";
  return 0;
}
