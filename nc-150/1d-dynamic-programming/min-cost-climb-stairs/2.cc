// top down dynamic programming (memoization)

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
