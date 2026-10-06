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
