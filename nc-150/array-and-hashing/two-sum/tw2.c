/* Given an array of integers `nums` and an integer `target`, return the indices i and j such that `nums[i] + nums[j] ==
 * target` and `i != j`. You may assume that every input has exactly one Pair of indices i and j that satisfy the
 * condition. Return the answer with the smaller index first.
 *
 * In this program we will be using sorting and two pointer to solve the two sum problem in C.
 * Time complexity - O(nlogn) or O(n^2) according to the qsort implementation
 * Space complexity - O(n), because the size of `c_arr_t` grows with the size of input `arr`
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int i, j;
} idx_t;

typedef struct {
  int el;
  int i;
} c_arr_t;

int cmpFn(const void *x, const void *y) {
  c_arr_t a = *(c_arr_t *)x;
  c_arr_t b = *(c_arr_t *)y;
  return a.el - b.el;
}

idx_t two_sum(int *arr, int target, int n) {
  idx_t x = {-1, -1};
  c_arr_t c_arr[n];
  for (int i = 0; i < n; i++) {
    c_arr[i].el = arr[i];
    c_arr[i].i = i;
  }
  qsort(c_arr, n, sizeof(c_arr_t), cmpFn);
  int low = 0, high = n - 1;
  while (low < high) {
    if ((c_arr + low)->el + (c_arr + high)->el == target) {
      if ((c_arr + low)->i < (c_arr + high)->i) {
        x.i = (c_arr + low)->i;
        x.j = (c_arr + high)->i;
      } else {
        x.i = (c_arr + high)->i;
        x.j = (c_arr + low)->i;
      }
      return x;
    } else if ((c_arr + low)->el + (c_arr + high)->el < target) {
      low++;
    } else {
      high--;
    }
  }
  return x;
}

int main(void) {
  int arr[] = {5, 3, 7, 2};
  idx_t idx = two_sum(arr, 7, 4);
  printf("%d %d\n", idx.i, idx.j);
  return 0;
}
