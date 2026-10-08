// recursive

#include <climits>
#include <vector>

class Solution {
  int c = 0;

  int recurs(std::vector<int> &cost, int step) {
    if (step >= cost.size())
      return c;
    c += cost[step];
    return recurs(cost, cost[step + 1] < cost[step + 2] ? step + 1 : step + 2);
  }

  int min_cost(std::vector<int> &cost) { return recurs(cost, (cost[0] < cost[1]) ? 0 : 1); }
};
