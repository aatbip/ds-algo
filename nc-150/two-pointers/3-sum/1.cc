/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] where,
 * nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.
 * The output should not contain any duplicate triplets. You may return the output and the triplets in any order.
 *
 * Example- Input: vector<int> nums = {-1,0,1,2,-1,-4}
 *          Output: {{-1,-1,2},{-1,0,1}}
 * */

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> three_sum(vector<int> &nums) {
    set<vector<int>> set;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        for (int k = j + 1; k < nums.size(); k++) {
          if (nums[i] + nums[j] + nums[k] == 0) {
            set.insert({nums[i], nums[j], nums[k]});
          }
        }
      }
    }
    return vector<vector<int>>{set.begin(), set.end()};
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
