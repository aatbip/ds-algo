#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int m = INT_MIN;

public:
  int recurs(vector<int> &nums, int k) {
    if (k >= nums.size())
      return 0;
    return max(nums[k] + recurs(nums, k + 2), recurs(nums, k + 1));
  }

  int max_rob(vector<int> &nums) { return recurs(nums, 0); }
};

int main(void) {
  Solution s;
  vector<int> nums = {1, 1, 3, 3};
  cout << s.max_rob(nums) << "\n";

  return 0;
}
