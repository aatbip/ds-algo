/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] where,
 * nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.
 * The output should not contain any duplicate triplets. You may return the output and the triplets in any order.
 *
 * Example- Input: vector<int> nums = {-1,0,1,2,-1,-4}
 *          Output: {{-1,-1,2},{-1,0,1}}
 *
 * This program uses brute force to solve the problem. It uses `set` data structure so that only unique elements
 * will be stored i.e. we don't want to store duplicate triplets. Arrays should be sorted so that duplicate
 * triplets in different order (such as [-1,-1,2] and [2,-1,-1]) won't get stored.
 *
 * Time complexity- O(n^3)
 * Space complexity- O(m)
 * Where, 'm' is the number of unique triplets and 'n' is the length of the array
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
