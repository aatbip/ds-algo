#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
private:
  std::vector<std::vector<int>> res;
  int sum = 0;

  void bt(std::vector<int> &nums, std::vector<int> &path, int start, int target) {
    if (sum == target) {
      res.push_back(path);
      return;
    }

    for (int j = start; j < nums.size(); j++) {
      if (sum + nums[j] > target) {
        return;
      }
      path.push_back(nums[j]);
      sum += nums[j];
      bt(nums, path, j, target);
      path.pop_back();
      sum -= nums[j];
    }
  }

public:
  std::vector<std::vector<int>> comb_sum(std::vector<int> candidates, int target) {
    std::vector<int> path;
    std::sort(candidates.begin(), candidates.end());
    bt(candidates, path, 0, target);
    return res;
  }
};

int main(void) {
  Solution s;
  std::vector<int> nums = {2, 5, 6, 9};
  std::vector<std::vector<int>> res = s.comb_sum(nums, 9);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      std::cout << res[i][j] << " ";
    }
    std::cout << "\n";
  }
}
