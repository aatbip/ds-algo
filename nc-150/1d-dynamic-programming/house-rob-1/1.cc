/*198. House Robber-
 * You are given an integer array nums where nums[i] represents the amount of money the ith house has.
 * The houses are arranged in a straight line, i.e. the ith house is the neighbor of the (i-1)th and (i+1)th house.
 * You are planning to rob money from the houses, but you cannot rob two adjacent houses because the security system
 * will automatically alert the police if two adjacent houses were both broken into. Return the maximum amount of money
 * you can rob without alerting the police.
 *
 * Solution- DP top down memoization.
 *
 * Time complexity- O(n)
 * Space complexity- O(n)
 *
 * */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  vector<int> cache;

public:
  int recurs(vector<int> &nums, int k) {
    if (k >= nums.size())
      return 0;
    if (cache[k] != -1)
      return cache[k];
    return cache[k] = max(nums[k] + recurs(nums, k + 2), recurs(nums, k + 1));
  }

  int max_rob(vector<int> &nums) {
    cache.resize(nums.size() + 1, -1);
    return recurs(nums, 0);
  }
};

int main(void) {
  Solution s;
  vector<int> nums = {1, 1, 3, 3};
  cout << s.max_rob(nums) << "\n";

  return 0;
}
