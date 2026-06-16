#include <list>
#include <unordered_map>
#include <utility>

class LRUCache {
  int capacity;
  std::list<std::pair<int, int>> list;
  std::unordered_map<int, std::list<int>::iterator> map;

  LRUCache(int capacity) : capacity{capacity} {}

  void put(int key, int value) {}
};
