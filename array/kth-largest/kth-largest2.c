/*Given an integer array nums and an integer k, return the kth largest element in the array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * Ex: Input: nums = [3,2,1,5,6,4], k = 2
 *     Output: 5
 *
 * In this program, we solve this problem by implementing the quickselect algorithm in C.
 */

#include <stdlib.h>

inline void swap(int *a, int *b) {
  int tempA = *a;
  *a = *b;
  *b = tempA;
}

int partition(int *nums, int left, int right, int pivot_index) {
  int pivot = *(nums + pivot_index);
  swap(&nums[right], &nums[pivot_index]);
  int p = left;
  for (int i = left; i < right; i++) {
    if (nums[i] < pivot) {
      swap(&nums[p], &nums[i]);
      p++;
    }
  }
  swap(&nums[right], &nums[pivot_index]);
  return p;
}

int kth_largest(int *nums, int numsSize, int k) {
  int left = 0, right = numsSize;
  int pivot_index = rand() % (right - left + 1) + left;

  for (;;) {
  }
}

int main(void) {

  int nums[] = {3, 2, 1, 5, 6, 4};

  return 0;
}
