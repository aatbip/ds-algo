#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
  int max_chunk(std::vector<int> &nums) {
    std::stack<int> stack;
    for (int i = 0; i < nums.size(); i++) {
      if (!stack.empty() && stack.top() >= nums[i]) {
        int top = stack.top();
        while (!stack.empty() && stack.top() >= nums[i]) {
          stack.pop();
        }
        stack.push(top);
      } else {
        stack.push(nums[i]);
      }
    }
    return stack.size();
  }
};

int main(void) {
  Solution s;
  std::vector<int> nums = {6, 5, 4, 3, 2};
  std::cout << s.max_chunk(nums) << "\n";
}
