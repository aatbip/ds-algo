/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given
 * target value. If target is not found in the array, return [-1, -1]. You must write an algorithm with O(log n) runtime
 * complexity.
 *
 * Solution- Solved using binary search. Find the first occurence using `find_first` then last occurence using
 * `find_last` if any.
 *
 * Time complexity- O(log n) + O(log n) = O(2 log n) = O(log n)
 * Space complexity- O(1)
 * */

#include <iostream>
#include <vector>

class Solution {

  int find_last(std::vector<int> &nums, int target) {
    int res = -1;
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] == target) {
        res = mid;
        low = mid + 1;
      } else if (target > nums[mid]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return res;
  }

  int find_first(std::vector<int> &nums, int target) {
    int res = -1;
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] == target) {
        res = mid;
        high = mid - 1;
      } else if (target > nums[mid]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return res;
  }

public:
  std::vector<int> search_range(std::vector<int> &nums, int target) {
    int first = find_first(nums, target);
    if (first == -1) {
      return {-1, -1};
    }
    return {first, find_last(nums, target)};
  }
};

int main(void) {
  Solution s;
  std::vector<int> nums = {5, 7, 7, 8, 8, 10};
  std::vector<int> res = s.search_range(nums, 8);
  for (int &n : res) {
    std::cout << n << " ";
  }
  return 0;
}
