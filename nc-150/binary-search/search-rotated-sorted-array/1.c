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
  int l = 0, h = numsSize - 1;
  int mid = (l + h) / 2;
  if (l == h) {
    return (target == nums[l]) ? l : -1;
  }
  if (nums[l] <= nums[mid]) {
    if (target == nums[mid + 1]) {
      return mid + 1;
    }
    int res;
    res = binary_search(nums, numsSize, l, mid, target);
    if (res == -1) {
      res = binary_search(nums, numsSize, mid + 2, h, target);
    }
    return res;
  }
  if (nums[l] > nums[mid]) {
    if (target == nums[mid - 1]) {
      return mid - 1;
    }
    int res;
    res = binary_search(nums, numsSize, mid, h, target);
    if (res == -1) {
      res = binary_search(nums, numsSize, l, mid - 2, target);
    }
    return res;
  }
  return -1;
}

int main(void) {
  int nums[] = {1, 3};
  printf("%d\n", search_rotated_sorted(nums, 2, 1));
  return 0;
}
