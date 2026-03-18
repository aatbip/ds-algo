#include <algorithm>
#include <climits>
#include <iostream>
#include <string>

class Solution {
public:
  std::string smallInt(std::string num, int k) {
    std::string stack = "";
    for (char c : num) {
      while (!stack.empty() && k > 0 && stack.back() > c) {
        stack.pop_back();
        k--;
      }
      stack.push_back(c);
    }
    return stack;
  }
};

int main(void) {
  Solution s;
  // std::string num = "33526221184202197273";
  std::string num = "1432219";
  std::cout << s.smallInt(num, 3) << "\n";
  return 0;
}
