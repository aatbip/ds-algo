/* Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except
 * nums[i]. Each product is guaranteed to fit in a 32-bit integer.
 * Example: Input: nums = [1,2,4,6]
 *          Output: [48,24,12,8]
 *
 * This problem can be solved using brute force approach which gives time complexity of O(n^2). In this program, we will
 * be using prefex-suffix (prefix sum) technique to solve this problem.
 *
 * Time complexity- O(n)
 * Space complexity- O(n)
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *prod(int *arr, int n) {
  int prefix_arr[n];
  memset(prefix_arr, 0, sizeof(prefix_arr));
  int suffix_arr[n];
  memset(suffix_arr, 0, sizeof(suffix_arr));
  int *prod = malloc(sizeof(int) * n);
  prefix_arr[0] = 1;
  suffix_arr[n - 1] = 1;
  for (int i = 1; i < n; i++) {
    prefix_arr[i] = arr[i - 1] * prefix_arr[i - 1];
  }
  for (int i = n - 2; i >= 0; i--) {
    suffix_arr[i] = arr[i + 1] * suffix_arr[i + 1];
  }
  for (int i = 0; i < n; i++) {
    prod[i] = prefix_arr[i] * suffix_arr[i];
  }
  return prod;
}

int main(void) {
  int arr[] = {1, 2, 4, 6};
  int *p = prod(arr, 4);
  for (int i = 0; i < 4; i++) {
    printf("%d ", p[i]);
  }
  return 0;
}
