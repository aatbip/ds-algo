/*Climbing stairs-
 *You are given an integer n representing the number of steps to reach the top of a staircase. You can climb with either
 *1 or 2 steps at a time. Return the number of distinct ways to climb to the top of the staircase.
 *
 * Solution- Solved using dynamic programming top-down approach which is also known as memoization.
 * Time complexity- O(n)
 * Space complexity- O(n)
 * */

#include <iostream>
#include <vector>
class Solution {
  std::vector<int> cache;

  int recurs(int step, int n) {
    if (step == n)
      return 1;
    if (step > n)
      return 0;
    if (cache[step] != -1)
      return cache[step];
    return cache[step] = recurs(step + 1, n) + recurs(step + 2, n);
  };

public:
  int climb_stairs(int n) {
    cache.resize(n, -1);
    return recurs(0, n);
  }
};

int main(void) {
  Solution s;
  std::cout << s.climb_stairs(44) << "\n";
}
