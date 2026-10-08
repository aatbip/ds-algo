// recursive

#include <climits>
#include <iostream>
#include <vector>

class Solution {
  int c = 0;

  int recurs(std::vector<int> &cost, int step) {
    if (step + 1 >= cost.size())
      return c;
    c += cost[step];
    return recurs(cost, cost[step + 1] < cost[step + 2] ? step + 1 : step + 2);
  }

public:
  int min_cost(std::vector<int> &cost) { return recurs(cost, (cost[0] < cost[1]) ? 0 : 1); }
};

int main(void) {
  Solution s;
  std::vector<int> cost = {1, 2, 100, 1};
  std::cout << s.min_cost(cost) << "\n";
}
