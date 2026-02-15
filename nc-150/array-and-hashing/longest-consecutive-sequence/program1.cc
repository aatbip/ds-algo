/* Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be
 * formed. A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous
 * element. The elements do not have to be consecutive in the original array.
 *
 * Example: Input: int nums = {2,20,4,10,3,4,5}
 *          Output: 4
 *          Explanation: The longest consecutive sequence is {2, 3, 4, 5}.
 *
 * In this program we solve the problem using brute force method. Even though the brute force methods are generally
 * not the optimal ones but it is a good starting point to get the intuition behind complex problems and a necessary
 * way towards creating more optimal algorithms to solve the problem.
 *
 * Time complexity- O(n^2), because in this solution we are not checking if there exist number that is less than
 * `nums[i]` so we end up checking the consecutive sequence for all the numbers in the array.
 * Space complexity- O(n)
 */

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int longest_consecutive(vector<int> &nums) {
    unordered_set<int> nums_set = {nums.begin(), nums.end()};
    int n = 0;
    for (int i = 0; i < nums_set.size(); i++) {
      int temp_n = 1;
      while (nums_set.find(nums[i] + temp_n) != nums_set.end()) {
        temp_n++;
      }
      n = max(n, temp_n);
    }
    return n;
  }
};

int main(void) {
  Solution s;
  // vector<int> nums = {2, 20, 4, 10, 3, 4, 5};
  // vector<int> nums = {0, 3, 2, 5, 4, 6, 1, 1};
  vector<int> nums = {0, 0, -1};
  cout << s.longest_consecutive(nums) << "\n";
  return 0;
}
