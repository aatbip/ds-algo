// dyn prog bottom up approach for the same prob

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
};

int main(void) {
  Solution s;
  std::cout << s.climbing_stairs(5) << "\n";
}
