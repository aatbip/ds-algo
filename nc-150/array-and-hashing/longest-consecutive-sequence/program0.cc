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
    int n = 0;
    for (int i = 0; i < num_set.size(); i++) {
      if (num_set.count(nums[i] - 1))
        continue; // continue if lower number is present
      int temp_n = 1;
      while (num_set.count(nums[i] + temp_n))
        temp_n++;
      if (temp_n > n)
        n = temp_n;
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
