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
 * Solution: Used the standard template library's `list` data structure to realize the doubly linked list for LRU cache.
 * Solved put and get in O(1) time complexity using the STL's `map` for O(1) lookup.
 *
 * Space complexity- O(n)
 * */

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
    if (it != map.end()) {
      it->second->second = value;
      list.splice(list.end(), list, it->second);
    } else {
      if (capacity == list.size()) {
        map.erase(list.front().first);
        list.pop_front();
      }
      list.push_back({key, value});
      map[key] = --list.end();
    }
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
