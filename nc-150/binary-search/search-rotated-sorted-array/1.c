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
}

int main(void) {
  int nums[] = {1, 3};
  printf("%d\n", search_rotated_sorted(nums, 2, 1));
  return 0;
}
