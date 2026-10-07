/*Climbing stairs-
 *You are given an integer n representing the number of steps to reach the top of a staircase. You can climb with either
 *1 or 2 steps at a time. Return the number of distinct ways to climb to the top of the staircase.
 *
 * Solution- Solved using dynamic programming bottom up approach.
 * Time complexity- O(n)
 * Space complexity- O(n)
 * */

#include <iostream>
#include <vector>

class Solution {
public:
  int climbing_stairs(int n) {
    if (n <= 2)
      return n;
    std::vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
  /*  int climbing_stairs(int n) {
      if (n <= 2)
        return n;
      int first = 1, second = 2;
      for (int i = 3; i <= n; i++) {
        int res = first + second;
        first = second;
        second = res;
      }
      return second;
    }*/
};

int main(void) {
  Solution s;
  std::cout << s.climbing_stairs(44) << "\n";
}
