
#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <vector>
class Solution {
public:
  int find_unsorted_subarray(std::vector<int> &nums) {
    std::stack<int> stack;
    int l = INT_MAX;
    int r = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      while (!stack.empty() && nums[stack.top()] > nums[i]) {
        l = std::min(l, stack.top());
        stack.pop();
      }
      stack.push(i);
    }
    while (!stack.empty()) {
      stack.pop();
    }
    for (int i = nums.size() - 1; i >= 0; i--) {
      while (!stack.empty() && nums[stack.top()] < nums[i]) {
        r = std::max(r, stack.top());
        stack.pop();
      }
      stack.push(i);
    }
    return l > r ? 0 : r - l + 1;
  }
};

int main(void) {
  Solution s;
  // std::vector<int> nums = {1, 2, 3, 4};
  // std::vector<int> nums = {1, 2, 3, 4};
  // std::vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
  // std::vector<int> nums = {1, 3, 2, 2, 2};
  std::vector<int> nums = {2, 1};

  std::cout << s.find_unsorted_subarray(nums) << "\n";

  return 0;
}
