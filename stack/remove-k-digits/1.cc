/*Given string num representing a non-negative integer num, and an integer k, return the
 * smallest possible integer after removing k digits from num.
 *
 * This program solves the problem using a monotonic stack and greedy method. It is a greedy technique because
 * at each stage we make a locally optimal decision by choosing to pop() the number that is greater than the current
 * number to reach the overall optimal solution. In this way we maintain a monotonic increasing stack.
 * */

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
    while (k-- > 0 && !stack.empty()) {
      stack.pop_back();
    }
    size_t pos = stack.find_first_not_of('0');
    stack = (pos == std::string::npos) ? "0" : stack.substr(pos);
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
