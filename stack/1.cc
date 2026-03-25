#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
  std::string unique_smallest(std::string str) {
    std::vector<int> map(26, 0);
    std::string stack;
    std::vector<int> last(26);
    for (int i = 0; i < str.size(); i++) {
      last[str[i] - 'a'] = i;
    }
    for (int i = 0; i < str.size(); i++) {
      if (map[str[i] - 'a'] == 0) {
        while (!stack.empty() && stack.back() > str[i] && last[stack.back() - 'a'] > i) {
          map[stack.back() - 'a']--;
          stack.pop_back();
        }
        stack.push_back(str[i]);
        map[str[i] - 'a']++;
      }
    }
    return stack;
  }
};

int main(void) {
  Solution s;
  std::string str = "cbacdcbc";
  std::cout << s.unique_smallest(str) << "\n";
  return 0;
}
