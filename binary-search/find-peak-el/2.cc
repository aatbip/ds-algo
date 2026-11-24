/*162. Find Peak Element-
 * A peak element is an element that is strictly greater than its neighbors.
 * Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple
 * peaks, return the index to any of the peaks. You may imagine that nums[-1] = nums[n] = -∞. In other words, an element
 * is always considered to be strictly greater than a neighbor that is outside the array. You must write an algorithm
 * that runs in O(log n) time.
 *
 * Solution-
 * Time complexity: O(log n), because each iteration discards about half of the total array range
 * Space complexity: O(n)
 * */
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
      int mid = low + (high - low) / 2; //(low+high)>>1 is equivalent
      if (nums[mid] < nums[mid + 1]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
};
