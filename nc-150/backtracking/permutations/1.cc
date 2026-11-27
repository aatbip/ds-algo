/* 46. Permutations-
 *Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any
 *order.
 *
 * Solution- Solved using recursive BT. The `used` boolean array is used to track the used integers.
 *
 * Time complexity-
 * O(n*n!), 'n' time recursive calls and 'n!' for permutation
 * Space complexity-
 * O(n), for recursion depth
 * */

#include <vector>
using namespace std;

class Solution {
  vector<vector<int>> res;

private:
  void bt(vector<int> &nums, vector<int> &path, vector<bool> &used) {
    if (path.size() == nums.size()) {
      res.push_back(path);
      return;
    }
    for (int j = 0; j < nums.size(); j++) {
      if (used[j] == true)
        continue;
      path.push_back(nums[j]);
      used[j] = true;
      bt(nums, path, used);
      path.pop_back();
      used[j] = false;
    }
  }

public:
  vector<vector<int>> permutate(vector<int> &nums) {
    vector<bool> used(nums.size(), false);
    vector<int> path;
    bt(nums, path, used);
    return res;
  }
};
