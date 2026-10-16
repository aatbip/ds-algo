#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
  int longest_substring(std::string s, int k) {
    int res = 0;
    std::unordered_map<char, int> map;
    int l = 0;
    int r = 1;
    map[s[l]]++;
    while (l < r && r < s.size()) {
      map[s[r]]++;
      if (map[s[r]] >= k)
        res = r - l + 1;
      r++;
    }
    return res;
  }
};

int main(void) {
  Solution s;
  std::string str = "ababbc";

  std::cout << s.longest_substring(str, 2) << "\n";

  return 0;
}
