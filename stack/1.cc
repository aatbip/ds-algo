#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
  std::string unique_smallest(std::string str) {
    std::vector<int> map(26, 0);
    std::stack<char> stack;
    std::vector<int> last(26);
    for (int i = 0; i < str.size(); i++) {
      last[str[i] - 'a'] = i;
    }
    for (int i = 0; i < str.size(); i++) {
      if (map[str[i] - 'a'] == 0) {
        while (!stack.empty() && stack.top() > str[i] && last[stack.top() - 'a'] > i) {
          map[stack.top() - 'a']--;
          stack.pop();
        }
        stack.push(str[i]);
        map[str[i] - 'a']++;
      }
    }
    std::string s = "";
    while (!stack.empty()) {
      s += stack.top();
      stack.pop();
    }
    std::reverse(s.begin(), s.end());
    return s;
  }
};

int main(void) {
  Solution s;
  std::string str = "cbacdcbc";
  std::cout << s.unique_smallest(str) << "\n";
  return 0;
}
