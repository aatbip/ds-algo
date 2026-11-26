/*40. Combination Sum II-
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in
 * candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the
 * combination. Note: The solution set must not contain duplicate combinations.
 *
 * Solution-
 * Solved using recursive backtracking.
 *
 * Time complexity- O(2^n)
 * Space complexity- O(k * x) where k is the average length of each combination and x is the total number of valid
 * combinations. This is because we store all valid combinations in the result list. Additionally O(n) for recursive
 * call stack. [from lc solutions, not able to understand with broad clarity. bt is tough... :D]
 *
 * */

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
