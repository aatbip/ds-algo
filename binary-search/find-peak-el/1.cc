/*162. Find Peak Element-
 * A peak element is an element that is strictly greater than its neighbors.
 * Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple
 * peaks, return the index to any of the peaks. You may imagine that nums[-1] = nums[n] = -∞. In other words, an element
 * is always considered to be strictly greater than a neighbor that is outside the array. You must write an algorithm
 * that runs in O(log n) time.
 *
 * Solution-
 * Solved using brute force.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 * */

#include <vector>
using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int res;
    for (int i = 0; i < nums.size(); i++) {
      if (i == 0) {
        if (nums[i] > nums[i + 1])
          res = i;
      } else if (i == nums.size() - 1) {
        if (nums[i] > nums[i - 1])
          res = i;
      } else {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
          res = i;
      }
    }
    return res;
  }
};
