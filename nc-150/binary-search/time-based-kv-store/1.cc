/*Implement a time-based key-value data structure that supports:
 * -> Storing multiple values for the same key at specified time stamps
 * -> Retrieving the key's value at a specified timestamp
 *
 * Implement the TimeMap class:
 * -> TimeMap() Initializes the object.
 * -> void set(String key, String value, int timestamp) Stores the key key with the value value at the given time
 * timestamp.
 * -> String get(String key, int timestamp) Returns the most recent value of key if set was previously called on
 * it and the most recent timestamp for that key prev_timestamp is less than or equal to the given timestamp
 * (prev_timestamp <= timestamp). If there are no values, it returns "".
 *
 * Note: For all calls to set, the timestamps are in strictly increasing order.
 *
 * We use hash map and vector of pair data structures to achieve the solution.
 *
 * Time complexity -
 * set method: O(n)
 * get method: O(logn), where 'n' is the size of the vector
 *
 * Space complexity -
 * O(m * n), where 'm' is the total number of keys and 'n' is the total number of values for a key
 *
 * */

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class TimeMap {
  std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> map;

public:
  void set(std::string key, std::string value, int timeStamp) { map[key].push_back({value, timeStamp}); }

  std::string get(std::string key, int timeStamp) {
    auto &vec = map[key];
    std::string res = "";
    int l = 0, h = vec.size() - 1;
    while (l <= h) {
      int mid = (l + h) / 2;
      if (vec[mid].second > timeStamp) {
        h = mid - 1;
      }
      if (vec[mid].second <= timeStamp) {
        l = mid + 1;
        res = vec[mid].first;
      }
    }
    return res;
  }
};

int main(void) {
  TimeMap map;
  map.set("hello", "world", 1);
  map.set("dog", "milo", 2);

  std::cout << map.get("dog", 4) << "\n";
  return 0;
}
