
#include <iostream>
#include <stack>
#include <vector>
class Solution {
public:
  int find_unsorted_subarray(std::vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l <= (int)nums.size() - 1 && nums[l] < nums[l + 1]) {
      l++;
    }
    while (r > 0 && nums[r] >= nums[r - 1]) {
      std::cout << "running: " << nums[l] << " " << nums[l - 1] << "\n";
      r--;
    }
    std::cout << "l: " << l << "\n";
    std::cout << "r: " << l << "\n";
    return r > l ? r - l + 1 : 0;
  }
};

int main(void) {
  Solution s;
  // std::vector<int> nums = {1, 2, 3, 4};
  // std::vector<int> nums = {1, 2, 3, 4};
  // std::vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
  std::vector<int> nums = {1, 3, 2, 2, 2};

  std::cout << s.find_unsorted_subarray(nums) << "\n";

  return 0;
}
