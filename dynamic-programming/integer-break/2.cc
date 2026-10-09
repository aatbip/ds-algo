/* 343. Integer Break -
 * Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the
 * product of those integers. Return the maximum product you can get.
 *
 * Solution-
 *
 * Time complexity-
 * Space complexity-
 */

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int integer_break(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
      for (int j = 1; j <= i - 1; j++) {
        dp[i] = std::max(dp[i], std::max(j * (i - j), j * dp[i - j]));
      }
    }
    return dp[n];
  }
};

int main(void) {
  Solution s;
  std::cout << s.integer_break(5) << "\n";
}
