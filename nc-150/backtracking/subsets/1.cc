#include <iostream>
#include <vector>

class Solution {
  std::vector<std::vector<int>> res;

  std::vector<std::vector<int>> bt(std::vector<int> &nums, int start, std::vector<int> &subset) {
    res.push_back(subset);
    for (int j = start; j < nums.size(); j++) {
      subset.push_back(nums[j]);
      bt(nums, start + 1, subset);
      subset.pop_back();
    }
    return res;
  }

public:
  std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    std::vector<int> subset;
    return bt(nums, 0, subset);
  }
};

int main(void) {
  Solution s;
  std::vector<int> nums = {1, 2, 3};
  std::vector<std::vector<int>> res = s.subsets(nums);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      std::cout << res[i][j] << " ";
    }
    std::cout << "\n";
  }
}
