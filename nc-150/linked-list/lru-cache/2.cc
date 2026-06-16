#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>

class LRUCache {
  int capacity;
  std::list<std::pair<int, int>> list;
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;

public:
  LRUCache(int capacity) : capacity{capacity} {}

  void put(int key, int value) {
    auto it = map.find(key);
    if (it == map.end()) {
      if (capacity == list.size()) {
        map.erase(list.front().first);
        list.pop_front();
      }
    }
    list.push_back({key, value});
    map[key] = --list.end();
  }

  int get(int key) {
    auto it = map.find(key);
    if (it == map.end())
      return -1;
    list.splice(list.end(), list, it->second);
    return it->second->second;
  }
};

int main(void) {
  LRUCache *cache = new LRUCache(2);
  cache->put(2, 1);
  cache->put(2, 2);
  std::cout << cache->get(2) << "\n";
  cache->put(1, 1);
  cache->put(4, 1);
  std::cout << cache->get(2) << "\n";
  delete cache;
  return 0;
}
