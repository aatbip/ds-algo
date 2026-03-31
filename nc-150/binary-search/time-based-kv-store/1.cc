
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class TimeMap {
  std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> map;

public:
  void set(std::string key, std::string value, int timeStamp) { map[key].push_back({value, timeStamp}); }
};

int main(void) { return 0; }
