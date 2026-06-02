/*You are given two integer arrays nums1 and nums2 of size m and n respectively, where each is sorted in ascending
 * order. Return the median value among all elements of the two arrays.
 *
 *Your solution must run in O(log(m+n)) time.
 *
 * Median: A median of a set of numbers is a value separating the higher half from the lower half. In case of odd sized
 * array, median is the element in the middle index. In case of even sized array, median is the average of the two
 * adjacent middle elements.
 *
 * Time complexity: O(logm + logn) = O(log(m+n)), where 'm' and 'n' are the length of two arrays respectively
 * Space complexity: O(1)
 * */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  double medianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() > nums2.size()) {
      return medianSortedArrays(nums2, nums1);
    }
    int l = 0, r = nums1.size();
    while (l <= r) {
      int part1 = (l + r) / 2;
      int part2 = (nums1.size() + nums2.size() + 1) / 2 - part1;
      int max_left1 = (part1 == 0) ? INT_MIN : nums1[part1 - 1];
      int max_left2 = (part2 == 0) ? INT_MIN : nums2[part2 - 1];
      int min_right1 = (part1 == nums1.size()) ? INT_MAX : nums1[part1];
      int min_right2 = (part2 == nums2.size()) ? INT_MAX : nums2[part2];

      if (max_left1 <= min_right2 && max_left2 <= min_right1) {
        if ((nums1.size() + nums2.size()) % 2 == 0) { // even case
          return (max(max_left1, max_left2) + min(min_right1, min_right2)) / 2.0;
        } else {
          return max(max_left1, max_left2);
        }
      } else if (max_left1 > min_right2) {
        r = part1 - 1;
      } else {
        l = part1 + 1;
      }
    }
    return 0;
  }
};

int main(void) {
  Solution s;
  vector<int> nums1 = {1, 2};
  vector<int> nums2 = {3, 4};

  cout << s.medianSortedArrays(nums1, nums2) << "\n";

  return 0;
}
