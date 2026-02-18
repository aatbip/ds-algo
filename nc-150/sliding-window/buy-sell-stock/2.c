/* Best time to buy and sell stock -
 * You are given an integer array prices where prices[i] is the price of NeetCoin on the ith day.
 * You may choose a single day to buy one NeetCoin and choose a different day in the future to sell it.
 * Return the maximum profit you can achieve. You may choose to not make any transactions, in which case the profit
 * would be 0.
 *
 * Example- Input: prices = [10,1,5,6,7,1]
 *          Output: 6
 *          Explanation: Buy prices[1] and sell prices[4], profit = 7 - 1 = 6.
 *
 * In this program, we solve the problem using dynamic programming.
 * Dynamic programming is a problem solving technique where we break down the problem into sub problems and store
 * the intermediate results to avoid recomputation. At each step, we maintain two pieces of state:
 * The minimum price seen so far.
 * The maximum profit achievable up to the current day.
 *
 * Dynamic Programming is a commonly used algorithmic technique used to optimize recursive solutions when same
 * subproblems are called again.
 *
 * The recurrence relation is:
 * minBuy[i] = min(minBuy[i-1], prices[i])
 * dp[i] = max(dp[i-1], prices[i] - minBuy[i])
 *
 * Since we only need the previous state, we compress it to O(1) space.
 *
 * This solution can also be interpreted as greedy.
 * At every step, we greedily update the minimum buying price, assuming that buying at the lowest price
 * seen so far is always optimal. This greedy choice is valid because the problem satisfies the optimal
 * substructure property.
 *
 * Greedy algorithm is a problem solving technique where we make a locally optimal choice at each step with
 * the hope that it leads to a globally optimal solution. In this program, at each day we greedily maintain
 * the minimum buying price seen so far. For every price, we compute the profit that would result if we sold
 * on that day, and update the maximum profit accordingly. This greedy choice works because buying at the lowest
 * price seen so far is always optimal for maximizing profit when selling in the future.
 *
 */

#include <stdio.h>

int max_profit(int *prices, int n) {
  int pr = 0, lowest = prices[0];
  for (int i = 0; i < n; i++) {
    int temp = prices[i] - lowest;
    if (temp > pr) {
      pr = temp;
    }
    if (prices[i] < lowest) {
      lowest = prices[i];
    }
  }
  return pr;
}

int main(void) {
  // int prices[] = {10, 1, 5, 6, 7, 1};
  // int prices[] = {10, 8, 7, 5, 2};
  int prices[] = {3, 2, 6, 5, 0, 3};
  printf("%d\n", max_profit(prices, 6));

  return 0;
}
