#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int max_rob(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n + 2, 0);
    for (int i = n - 1; i >= 0; i--) {
      dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
    }
    return dp[0];
  }
};

int main(void) {
  Solution s;
  vector<int> nums = {1, 1, 3, 3};
  cout << s.max_rob(nums) << "\n";

  return 0;
}
