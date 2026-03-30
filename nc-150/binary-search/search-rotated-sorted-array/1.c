/* You are given an array of length n which was originally sorted in ascending order. It has now
 * been rotated between 1 and n times. For example, the array nums = [1,2,3,4,5,6] might become:
 *
 * [3,4,5,6,1,2] if it was rotated 4 times.
 * [1,2,3,4,5,6] if it was rotated 6 times.
 *
 * Given the rotated sorted array nums and an integer target, return the index of target within
 * nums, or -1 if it is not present.
 *
 * You may assume all elements in the sorted rotated array nums are unique,
 *
 * A solution that runs in O(n) time is trivial, can you write an algorithm that runs in O(log n) time?
 *
 *
 * The program first find the index of the min in the rotated sorted array. Then we can form two sorted arrays
 * which are leftmost to min -1 and min to rightmost. Then we can perform binary search on these two distinct
 * sorted arrays.
 * */

#include <stdio.h>

int binary_search(int *nums, int n, int l, int h, int target) {
  while (l <= h) {
    int mid = (l + h) / 2;
    if (nums[mid] == target) {
      return mid;
    }
    if (nums[mid] > target) {
      h = mid - 1;
    }
    if (nums[mid] < target) {
      l = mid + 1;
    }
  }
  return -1;
}

int search_rotated_sorted(int *nums, int numsSize, int target) {
  // first find index of min in rotated sorted array
  int l = 0, h = numsSize - 1;
  while (l < h) {
    int mid = (l + h) / 2;
    if (nums[mid] > nums[h]) {
      l = mid + 1;
    }
    if (nums[mid] < nums[h]) {
      h = mid;
    }
  }
  // first search through the left side
  int res = binary_search(nums, numsSize, 0, l - 1, target);
  if (res != -1) {
    return res;
  }
  res = binary_search(nums, numsSize, l, numsSize - 1, target);
  return res;
}

int main(void) {
  int nums[] = {3, 4, 5, 6, 1, 2};
  printf("%d\n", search_rotated_sorted(nums, 6, 3));
  return 0;
}
