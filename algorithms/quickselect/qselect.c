/* Quick select algorithm is used to select kth largest or kth smallest from the array. This algorithm is technically
 * same as quick sort but instead of sorting completely we stop further sorting as soon as we find the index of kth
 * largest or kth smallest.
 *
 * Algorithm -
 * Step 1: Find the pivot index. There are multiple ways to choose pivot index for optimal complexity. Here we use
 * this formula - pivot index = rand() % (right - left + 1) + left
 *
 *
 * */

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int *arr, int left, int right, int pivot_index) {
  int pivot_el = arr[pivot_index];
  swap(&arr[pivot_index], &arr[right]);
  int p = left;
  for (int i = left; i < right; i++) {
    if (arr[i] < pivot_el) {
      swap(&arr[i], &arr[p]);
      p++;
    }
  }
  swap(&arr[right], &arr[p]);
  return p;
}

int kth_largest(int *arr, int n, int k) {
  int left = 0, right = n - 1;
  int pivot_index = rand() % (right - left + 1) + left;
  for (;;) {
    int p = partition(arr, left, right, pivot_index);
    if (p == n - k) {
      return arr[p];
    } else if (p < n - k) {
      left = p + 1;
    } else {
      right = p - 1;
    }
  }
}

int main(void) {
  int arr[] = {2, 6, 5, 3, 10, 41, 21, 9};
  int kl = kth_largest(arr, 8, 4);
  printf("%d\n", kl);
  return 0;
}
