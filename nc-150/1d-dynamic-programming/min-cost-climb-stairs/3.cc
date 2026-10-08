/*You are given an array of integers cost where cost[i] is the cost of taking a step from the ith floor of a staircase.
 * After paying the cost, you can step to either the (i + 1)th floor or the (i + 2)th floor. You may choose to start at
 * the index 0 or the index 1 floor. Return the minimum cost to reach the top of the staircase, i.e. just past the last
 * index in cost.
 *
 * Solution- Solved using dynamic programming bottom up approach.
 *
 * Time complexity- O(n)
 * Space complexity- O(n)
 * O(1) in space optimized way.
 * */

#include <algorithm>
#include <vector>

class Solution {

  int min_cost(std::vector<int> &cost) {
    int n = cost.size();
    /*min total paid by the time arriving at ith floor. dp[0] and dp[1] are 0 because by the time we step at 0 or 1
     * floor, no amount is paid since we can start at either 0 or 1. 'dp' is the cost paid by the time of arriving
     * at that step while 'cost' is the cost paid when leaving any step.
     * */
    // n+1 because we need the cost paid by the time we arrive at top i.e. one step further the last step
    std::vector<int> dp(n + 1, 0);
    for (int i = 2; i <= n; i++) {
      /* at i=2, dp[2] which means amount to be paid to arrive at the 2nd step is calculated as dp[i-1] = dp[1] i.e.
       * amount paid to arrive at the 1st floor adding with cost[i-1] = cost[1] i.e. amount paid to leave the 1st floor.
       * Similar with [i-2] because we can take 1 or 2 steps at a time.
       * */
      dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[n];
  }

  int min_cost_space_optimized(std::vector<int> &cost) {
    int first = 0;
    int second = 0;
    for (int i = 2; i <= cost.size(); i++) {
      int temp = std::min(second + cost[i - 1], first + cost[i - 2]);
      first = second;
      second = temp;
    }
    return second;
  }
};
