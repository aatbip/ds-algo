/* Combination Sum I -
 * You are given an array of distinct integers nums and a target integer target. Your task is to return a list of all
 * unique combinations of nums where the chosen numbers sum to target.
 * The same number may be chosen from nums an unlimited number of times. Two combinations are the same if the frequency
 * of each of the chosen numbers is the same, otherwise they are different.
 * You may return the combinations in any order and the order of the numbers in each combination can be in any order.
 *
 * Solution -
 * Solved using sorting and recursive backtracking.
 *
 * Time complexity- O(2*(t/m))
 * Space complexity- O(t/m)
 * where t->target m->min value in nums
 *
 * */

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
