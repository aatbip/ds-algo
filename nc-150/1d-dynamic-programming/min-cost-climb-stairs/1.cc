// recursive

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

class Solution {
  int recurs(std::vector<int> &cost, int i) {
    if (i >= cost.size()) {
      return 0;
    }
    return cost[i] + std::min(recurs(cost, i + 1), recurs(cost, i + 2));
  }

public:
  int min_cost(std::vector<int> &cost) { return std::min(recurs(cost, 0), recurs(cost, 1)); }
};

int main(void) {
  Solution s;
  std::vector<int> cost = {10, 15, 20};
  std::cout << s.min_cost(cost) << "\n";
}
