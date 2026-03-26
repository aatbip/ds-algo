/* You are given an array of distinct integers nums, sorted in ascending
 * order, and an integer target. Implement a function to search for target
 * within nums. If it exists, then return its index, otherwise, return -1.
 *
 * Example- Input: nums = [-1,0,2,4,6,8], target = 4
 *          Output: 3
 *
 * This is a binary search implementation to search for a target in a sorted array.
 *
 * Time complexity - O(logn)
 * Space complexity - O(1)
 **/

#include <stdio.h>

int binary_search(int *nums, int size, int target) {
  int low = 0, high = size - 1;
  while (low <= high) {
    int mid = low + high / 2;
    if (*(nums + mid) == target)
      return 1;
    if (*(nums + mid) > target) {
      low = mid + 1;
    }
    if (*(nums + mid) < target) {
      high = mid - 1;
    }
  }
  return -1;
}

int main(void) {
  int nums[] = {-1, 0, 2, 4, 6, 8};
  printf("%d\n", binary_search(nums, 6, 2));
  return 0;
}
