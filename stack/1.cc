
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
class Solution {
public:
  std::string unique_smallest(std::string str) {
    std::unordered_map<char, int> map;
    std::stack<char> stack;
    for (char c : str) {
      while (!stack.empty() && stack.top() > c) {
        map[stack.top()]--;
        stack.pop();
      }
      if (map[c] == 0) {
        stack.push(c);
        map[c]++;
      }
    }
    std::string s = "";
    for (int i = 0; i < stack.size(); i++) {
      s += stack.top();
      stack.pop();
    }
    std::reverse(s.begin(), s.end());
    return s;
  }
};
