/*Implement the Least Recently Used (LRU) cache class LRUCache. The class should support the following operations:
 * -> LRUCache(int capacity) Initialize the LRU cache of size capacity.
 * -> int get(int key) Return the value corresponding to the key if the key exists, otherwise return -1.
 * -> void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to
 * the cache. If the introduction of the new pair causes the cache to exceed its capacity, remove the least recently
 * used key.
 *
 * A key is considered used if a get or a put operation is called on it. Ensure that get and put each run in
 * O(1) average time complexity.
 *
 * Solution: Implemented custom linked list and useful helpfer functions.
 * Solved put and get in O(1) time complexity using the STL's `map` for O(1) lookup.
 *
 * Space complexity- O(n)
 * */

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
    while (cur) {
      Node *next = cur->next;
      delete cur;
      cur = next;
    }
  }
};

int main(void) {
  LRUCache *cache = new LRUCache(2);
  cache->put(1, 1);
  cache->put(2, 2);
  std::cout << cache->get(1) << "\n";
  cache->put(3, 3);
  std::cout << cache->get(2) << "\n";
  cache->put(4, 4);
  std::cout << cache->get(1) << "\n";
  std::cout << cache->get(3) << "\n";
  std::cout << cache->get(4) << "\n";
  delete cache;
  return 0;
}
