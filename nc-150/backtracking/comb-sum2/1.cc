#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  vector<vector<int>> res;
  int sum = 0;

private:
  void bt(vector<int> &candidates, int target, vector<int> &path, int start) {
    if (sum == target) {
      res.push_back(path);
      return;
    }

    for (int j = start; j < candidates.size(); j++) {
      if (sum + candidates[j] > target) {
        return;
      }
      if (j > start && candidates[j] == candidates[j - 1])
        continue;
      path.push_back(candidates[j]);
      sum += candidates[j];
      bt(candidates, target, path, j + 1);
      path.pop_back();
      sum -= candidates[j];
    }
  }

public:
  vector<vector<int>> comb_sum2(vector<int> &candidates, int target) {
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    bt(candidates, target, path, 0);
    return res;
  }
};
