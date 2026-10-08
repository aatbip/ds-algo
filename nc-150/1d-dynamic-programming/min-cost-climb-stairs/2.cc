/*You are given an array of integers cost where cost[i] is the cost of taking a step from the ith floor of a staircase.
 * After paying the cost, you can step to either the (i + 1)th floor or the (i + 2)th floor. You may choose to start at
 * the index 0 or the index 1 floor. Return the minimum cost to reach the top of the staircase, i.e. just past the last
 * index in cost.
 *
 * Solution- Solved using dynamic programming top down approach (memoization).
 *
 * Time complexity- O(n)
 * Space complexity- O(n)
 * */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

class Solution {
  std::vector<int> cache;

  int recurs(std::vector<int> &cost, int i) {
    if (i >= cost.size()) {
      return 0;
    }
    if (cache[i] != -1) {
      return cache[i];
    }

    return cache[i] = cost[i] + std::min(recurs(cost, i + 1), recurs(cost, i + 2));
  }

public:
  int min_cost(std::vector<int> &cost) {
    cache.resize(cost.size(), -1);
    return std::min(recurs(cost, 0), recurs(cost, 1));
  }
};

int main(void) {
  Solution s;
  std::vector<int> cost = {10, 15, 20};
  std::cout << s.min_cost(cost) << "\n";
}
