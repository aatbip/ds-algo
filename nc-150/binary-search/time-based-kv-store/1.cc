
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
    std::vector<std::pair<std::string, int>> vec = map[key];
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
