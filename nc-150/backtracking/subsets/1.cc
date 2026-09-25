#include <iostream>

#include <vector>
class Solution {
  std::vector<std::vector<int>> res;

  std::vector<std::vector<int>> bt(std::vector<int> &nums, int i, std::vector<int> &subset) {
    res.push_back(subset);
    for (int j = i; j < nums.size(); j++) {
      subset.push_back(nums[i]);
      bt(nums, i + 1, subset);
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
