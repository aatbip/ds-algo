/*Given an array of positive integers nums and a positive integer target, return the minimal length
 * of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
 *
 * Example - Input: target = 7, nums = [2,3,1,2,4,3]
 *           Output: 2
 *           Explanation: The subarray [4,3] has the minimal length under the problem constraint.
 ***/

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

class Solution {
public:
  int min_subarray(std::vector<int> &nums, int target) {
    int l = 0;
    int res = INT_MAX;
    int sum = 0;
    for (int r = 0; r < nums.size(); r++) {
      sum += nums[r];
      while (sum >= target) {
        res = std::min(res, r - l + 1);
        sum -= nums[l++];
      }
    }
    return res == INT_MAX ? 0 : res;
  }
};

int main(void) {
  Solution s;
  std::vector<int> nums{2, 3, 1, 2, 4, 3};
  std::cout << s.min_subarray(nums, 7) << "\n";
  return 0;
}
