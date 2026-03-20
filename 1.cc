#include <climits>
#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
  bool find_123_pattern(std::vector<int> &nums) {
    std::stack<int> stack;
    int third = INT_MIN; //'2' element in 132 pattern
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (nums[i] < third)
        return true;
      while (!stack.empty() && nums[i] > stack.top()) {
        third = stack.top();
        stack.pop();
      }
      stack.push(nums[i]);
    }
    return false;
  }
};

int main(void) {
  Solution s;
  std::vector<int> nums = {-1, 3, 2, 0};
  std::cout << s.find_123_pattern(nums) << "\n";

  return 0;
}
