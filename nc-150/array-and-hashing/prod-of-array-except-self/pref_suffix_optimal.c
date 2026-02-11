/* Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except
 * nums[i]. Each product is guaranteed to fit in a 32-bit integer.
 * Example: Input: nums = [1,2,4,6]
 *          Output: [48,24,12,8]
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *prod(int *arr, int n) {
  int *prod_arr = malloc(sizeof(int) * n);
  memset(prod_arr, 0, sizeof(*prod_arr));
  prod_arr[0] = 1;
  for (int i = 1; i < n; i++) {
    prod_arr[i] = arr[i - 1] * prod_arr[i - 1];
  }
  int postfix = 1;
  for (int i = n - 1; i >= 0; i--) {
    prod_arr[i] = prod_arr[i] * postfix;
    postfix = postfix * arr[i];
  }
  return prod_arr;
}

int main(void) {
  int arr[4] = {1, 2, 3, 2};
  int *prod_arr = prod(arr, 4);
  for (int i = 0; i < 4; i++) {
    printf("%d ", prod_arr[i]);
  }
  free(prod_arr);
  return 0;
}
