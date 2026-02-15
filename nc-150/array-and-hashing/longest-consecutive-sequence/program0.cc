/* Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be
 * formed. A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous
 * element. The elements do not have to be consecutive in the original array.
 *
 * Example: Input: int nums = {2,20,4,10,3,4,5}
 *          Output: 4
 *          Explanation: The longest consecutive sequence is {2, 3, 4, 5}.
 *
 *
 *
 * */

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int longest_conse_seq_len(vector<int> &nums) {
    unordered_set<int> num_set = {nums.begin(), nums.end()};

    return 0;
  }
};

int main(void) {
  Solution s;
  vector<int> nums = {2, 20, 4, 10, 3, 5};
  s.longest_conse_seq_len(nums);
  return 0;
}
