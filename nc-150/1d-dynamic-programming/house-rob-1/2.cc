/*198. House Robber-
 * You are given an integer array nums where nums[i] represents the amount of money the ith house has.
 * The houses are arranged in a straight line, i.e. the ith house is the neighbor of the (i-1)th and (i+1)th house.
 * You are planning to rob money from the houses, but you cannot rob two adjacent houses because the security system
 * will automatically alert the police if two adjacent houses were both broken into. Return the maximum amount of money
 * you can rob without alerting the police.
 *
 * Solution- DP bottom up
 *
 * Time complexity- O(n)
 * Space complexity- O(n)
 * */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int max_rob(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n + 2, 0);
    for (int i = n - 1; i >= 0; i--) {
      dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
    }
    return dp[0];
  }
};

int main(void) {
  Solution s;
  vector<int> nums = {1, 1, 3, 3};
  cout << s.max_rob(nums) << "\n";

  return 0;
}
