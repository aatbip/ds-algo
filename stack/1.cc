
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

      stack.push(c);
    }
  }
};
