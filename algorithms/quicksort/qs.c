/* This program implements quicksort algorithm in C.
 * Time complexity -
 * Average case: O(nlogn)
 * Worst case: O(n^2)
 *
 * Space complexity -
 * Due to the stack overhead from recursion: O(logn)
 * in worst case: O(n^2)
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static inline void swap(int *a, int *b) {
  int tempA = *a;
  *a = *b;
  *b = tempA;
}

int partition(int *nums, int left, int right, int pivot_index) {
  int pivot = nums[pivot_index];
  swap(&nums[pivot_index], &nums[right]);
  int p = left;
  for (int i = left; i < right; i++) {
    if (nums[i] < pivot) {
      swap(&nums[i], &nums[p]);
      p++;
    }
  }
  swap(&nums[p], &nums[right]);
  return p;
}

void sort(int *nums, int n, int left, int right) {
  if (left >= right)
    return;
  int pivot_index = rand() % (right - left + 1) + left;
  int p = partition(nums, left, right, pivot_index);
  sort(nums, n, p + 1, right);
  sort(nums, n, left, p - 1);
}

void quicksort(int *nums, int n) {
  srand(time(NULL)); // seeding to make sure rand() generates variable sequence
  sort(nums, n, 0, n - 1);
}

int main(void) {

  int nums[] = {1, 6, 2, 1, 3, 6, 7, 5, 3, 2};
  quicksort(nums, 10);
  for (int i = 0; i < 10; i++) {
    printf("%d\n", nums[i]);
  }

  return 0;
}
