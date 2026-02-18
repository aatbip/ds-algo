/*You are given an integer array prices where prices[i] is the price of NeetCoin on the ith day.
 * You may choose a single day to buy one NeetCoin and choose a different day in the future to sell it.
 * Return the maximum profit you can achieve. You may choose to not make any transactions, in which case the profit
 * would be 0.
 *
 * Example- Input: prices = [10,1,5,6,7,1]
 *          Output: 6
 *          Explanation: Buy prices[1] and sell prices[4], profit = 7 - 1 = 6.
 *
 * */

int max_profit(int *prices, int n) {
  int pr = 0;
  int l = prices[0], r = n - 1;
  while (l < r) {
    if (prices[l] > prices[r])
      continue;
  }

  return pr;
}

int main(void) {
  int prices[] = {10, 1, 5, 6, 7, 1};
  return 0;
}
