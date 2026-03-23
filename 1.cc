
#include <stack>
#include <vector>
class Solution {
public:
  int find_unsorted_subarray(std::vector<int> &nums) {
    std::stack<int> stack;
    for (int i = 0; i < nums.size(); i++) {
      while (!stack.empty() && stack.top() > nums[i]) {
        stack.pop();
      }
      stack.push(nums[i]);
    }
    return stack.size();
  }
};
