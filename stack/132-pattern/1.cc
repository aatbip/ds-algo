/*Given an array of n integers nums, a 132 pattern is a subsequence of three integers
 * nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
 * Return true if there is a 132 pattern in nums, otherwise, return false.
 *
 * Example - Input: nums = [1,2,3,4]
 *           Output: false
 *           Explanation: There is no 132 pattern in the sequence.
 *
 *           Input: nums = [-1,3,2,0]
 *           Output: true
 *           Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 * */

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
