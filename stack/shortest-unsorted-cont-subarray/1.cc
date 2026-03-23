/*Given an integer array nums, you need to find one continuous subarray such that if you only sort
 * this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.
 * Return the shortest such subarray and output its length.
 *
 * Example:
 * Input: nums = [2,6,4,8,10,9,15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
 *
 * This program uses monotonic stack to solve the problem.
 *
 *
 * */

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
