/*Given an integer array nums and an integer k, return the kth largest element in the array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * Ex: Input: nums = [3,2,1,5,6,4], k = 2
 *     Output: 5
 *
 * In this program, we solve this problem by implementing the quickselect algorithm in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double get_time_ms() {
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  return (double)ts.tv_sec * 1000.0 + (double)ts.tv_nsec / 1000000.0;
}

static inline void swap(int *a, int *b) {
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
  swap(&nums[right], &nums[p]);
  return p;
}

int kth_largest(int *nums, int numsSize, int k) {
  int left = 0, right = numsSize - 1;
  for (;;) {
    int pivot_index = rand() % (right - left + 1) + left;
    int p = partition(nums, left, right, pivot_index);
    if (p == numsSize - k) {
      return nums[p];
    } else if (p < numsSize - k) {
      left = p + 1;
    } else {
      right = p - 1;
    }
  }
}

int main(void) {

  // int nums[] = {3, 2, 1, 5, 6, 4};
  // printf("%d\n", kth_largest(nums, 6, 2));

  int *nums = malloc(sizeof(int) * 10000000);
  for (int i = 0; i < 10000000; i++) {
    nums[i] = i;
  }

  double start = get_time_ms();
  for (int i = 1; i <= 100; i++) {
    printf("%d\n", kth_largest(nums, 10000000, i));
  }
  double end = get_time_ms();

  printf("Operation took %.3f ms\n", end - start);
  free(nums);

  return 0;
}
