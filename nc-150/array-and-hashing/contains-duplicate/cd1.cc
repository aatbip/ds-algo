/* Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.
 *
 *
 * Another solution is to sort the array and then check adjacent elements.
 * Time Complexity:
 * Sorting takes O(n log n). The subsequent linear scan takes O(n).
 * Total time complexity = O(max(nlogn, n)) = O(nlogn)
 * Space Complexity:
 * Depends on the sorting algorithm used:
 * - O(1) auxiliary space for in-place sorts like heapsort
 * - O(log n) stack space for quicksort/introsort (e.g., C++ std::sort)
 * - O(n) for mergesort
 */

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int contains_duplicate(std::vector<int> &vec) {
    std::sort(vec.begin(), vec.end());

    for (auto i = 0; i < vec.size(); i++) {
      if (vec[i] == vec[i - 1]) {
        return true;
      }
    }
    return false;
  }
};

int main(void) {
  Solution s;
  std::vector<int> arr{1, 2, 3, 4, 5, 2};
  std::cout << s.contains_duplicate(arr) << "\n";
  return 0;
}
