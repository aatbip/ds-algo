/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] where,
 * nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.
 * The output should not contain any duplicate triplets. You may return the output and the triplets in any order.
 *
 * Example- Input: vector<int> nums = {-1,0,1,2,-1,-4}
 *          Output: {{-1,-1,2},{-1,0,1}}
 *
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> three_sum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    unordered_map<int, int> count;
    for (int i : nums) {
      count[i]++;
    }
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); i++) {
      /*We are decrementing the frequency of nums[i] to indicate that this particular
       * element is currently in used and shouldn't be the `target` number later on.*/
      count[nums[i]]--;
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      for (int j = i + 1; j < nums.size(); j++) {
        /*We are decrementing the frequency of nums[j] to indicate that this particular
         * element is currently in used and shouldn't be the `target` number later on.*/
        count[nums[j]]--;
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;
        int target = -(nums[i] + nums[j]);
        if (count[target] > 0) {
          res.push_back({nums[i], nums[j], target});
        }
      }

      /*Increment the frequency of elements from `j=i+1` and onwards to ensure that the
       * frequency map is correct and elements are available for the next pass.*/
      for (int j = i + 1; j < nums.size(); j++) {
        count[nums[j]]++;
      }
    }
    return res;
  }
};

int main(void) {
  Solution s;
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> res = s.three_sum(nums);
  for (auto p : res) {
    for (int i : p) {
      cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}
