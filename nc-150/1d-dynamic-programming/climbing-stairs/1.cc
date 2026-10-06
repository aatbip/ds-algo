/*Climbing stairs-
 *You are given an integer n representing the number of steps to reach the top of a staircase. You can climb with either
 *1 or 2 steps at a time. Return the number of distinct ways to climb to the top of the staircase.
 *
 * Solution- Solved using recursion.
 * Time complexity- O(2^n)
 * Space complexity- O(n)
 * */

#include <iostream>
class Solution {
  int recurs(int step, int n) {
    if (step == n)
      return 1;
    if (step > n)
      return 0;
    return recurs(step + 1, n) + recurs(step + 2, n);
  }

public:
  int climb_stairs(int n) { return recurs(0, n); }
};

int main(void) {
  Solution s;
  std::cout << s.climb_stairs(44) << "\n";
}
