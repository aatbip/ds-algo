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
 * In this program we solve the problem using two pointer approach.
 *
 * Time complexity- O(n)
 * Space complexity- O(1)
 * */

#include <stdio.h>

int max_profit(int *prices, int n) {
  int pr = 0;
  int l = 0, r = 1;
  while (r < n) {
    if (prices[l] > prices[r]) {
      l = r;
      r++;
      continue;
    }
    int temp = prices[r] - prices[l];
    if (temp > pr) {
      pr = temp;
    }
    r++;
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
