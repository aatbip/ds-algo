/* Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be
 * formed. A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous
 * element. The elements do not have to be consecutive in the original array.
 *
 * Example: Input: int nums = {2,20,4,10,3,4,5}
 *          Output: 4
 *          Explanation: The longest consecutive sequence is {2, 3, 4, 5}.
 *
 *
 * This program solves the problem using hash set. The idea is to count for the presence of next consecutive number
 * only if the number lower than the current number is not present in the array.
 *
 * Time complexity- O(n), because only single for loop is present and look up to hash set is O(1) in the while loop
 * Space complexity- O(n), because `num_set` can grow with the size of `nums`
 *
 *
 * */

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int longest_conse_seq_len(vector<int> &nums) {
    unordered_set<int> num_set = {nums.begin(), nums.end()};
    int n = 0;
    for (int i = 0; i < num_set.size(); i++) {
      if (num_set.count(nums[i] - 1))
        continue; // continue if lower number is present
      int temp_n = 1;
      while (num_set.count(nums[i] + temp_n))
        temp_n++;
      n = max(n, temp_n);
    }
    return n;
  }
};

int main(void) {
  Solution s;
  // vector<int> nums = {2, 20, 4, 10, 3, 4, 5};
  vector<int> nums = {0, 3, 2, 5, 4, 6, 1, 1};
  cout << s.longest_conse_seq_len(nums) << "\n";
  return 0;
}
