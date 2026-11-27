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
