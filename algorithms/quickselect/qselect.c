/* Quick select algorithm is used to select kth largest or kth smallest from the array. This algorithm is technically
 * same as quick sort but instead of sorting completely we stop further sorting as soon as we find the index of kth
 * largest or kth smallest.
 *
 * In the program below we write quick select to find the kth largest.
 *
 * Algorithm -
 * Step 1: Find the pivot index. There are multiple ways to choose pivot index for optimal complexity. Here we use
 * this formula - pivot index = rand() % (right - left + 1) + left
 *
 * Step 2: Swap the element in the pivot index with the element in the right so that pivot element remains untouched.
 *
 * Step 3: Initialize `p = left`. Then loop from `i = left` until `i < right`. If ith element is smaller than the pivot
 * element then swap the ith element with `p` and increment `p`.
 *
 * Step 4: Swap the pivot element in the rightmost position to the index of 'p'. This makes sure that all the elements
 * to the left of pivot element in 'p' position is smaller and all the elements towards the right is larger but not
 * necessarily sorted.
 *
 * Step 5: Return 'p' then compare 'p' against 'n - k' then increment or decrement left and right position accordingly
 * (see code). If `p == n-k` then the element at 'p' is the correct kth element.
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
