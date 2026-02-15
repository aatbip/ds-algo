/*Given an array of integers numbers that is sorted in non-decreasing order. Return the indices (1-indexed)
 * of two numbers, [index1, index2], such that they add up to a given target number target and index1 < index2.
 * Note that index1 and index2 cannot be equal, therefore you may not use the same element twice.
 *
 * There will always be exactly one valid solution.
 * Example- Input: numbers = [1,2,3,4], target = 3
 *         Output: [1,2]
 *
 * This program uses hash map (one pass) to solve the above problem.
 *
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> two_sum(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      int temp = target - nums[i];
      if (map.find(temp) != map.end()) {
        return {map[temp] + 1, i + 1};
      }
      map[nums[i]] = i;
    }
    return {};
  }
};

int main(void) {
  Solution s;
  vector<int> nums = {1, 2, 3, 4};
  vector<int> res = s.two_sum(nums, 6);
  cout << res[0] << " " << res[1] << "\n";
  return 0;
}
