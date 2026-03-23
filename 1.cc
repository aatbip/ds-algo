
#include <iostream>
#include <stack>
#include <vector>
class Solution {
public:
  int find_unsorted_subarray(std::vector<int> &nums) {
    std::stack<int> stack;
    for (int i = 0; i < nums.size(); i++) {
      if (!stack.empty() && stack.top() > nums[i]) {
        int top = stack.top();
        while (!stack.empty() && stack.top() > nums[i]) {
          stack.pop();
        }
        stack.push(top);
      } else {
        stack.push(nums[i]);
      }
    }
    return stack.size() == nums.size() ? 0 : stack.size();
  }
};

int main(void) {
  Solution s;
  std::vector<int> nums = {2, 1};
  // std::vector<int> nums = {1, 2, 3, 4};
  // std::vector<int> nums = {2, 6, 4, 8, 10, 9, 15};

  std::cout << s.find_unsorted_subarray(nums) << "\n";

  return 0;
}
