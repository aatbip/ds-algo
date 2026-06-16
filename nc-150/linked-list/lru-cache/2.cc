#include <list>
#include <unordered_map>
#include <utility>

class LRUCache {
  int capacity;
  std::list<std::pair<int, int>> list;
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;

  LRUCache(int capacity) : capacity{capacity} {}

  void put(int key, int value) {
    auto it = map.find(key);
    if (it == map.end()) {
      if (capacity == list.size()) {
        map.erase(list.front().first);
        list.pop_front();
      }
      list.push_back({key, value});
      map[key] = --list.end();
    }
  }
};
