/* Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except
 * nums[i]. Each product is guaranteed to fit in a 32-bit integer.
 * Example: Input: nums = [1,2,4,6]
 *          Output: [48,24,12,8]
 *
 * This program solves the problem using the fact that if
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *prod(int *arr, int n) {
  int *p = malloc(sizeof(int) * n);
  memset(p, 0, sizeof(*p));
  int zero_count = 0;
  int prod = 1;
  for (int i = 0; i < n; i++) {
    if (arr[i] != 0) {
      prod *= arr[i];
    } else {
      zero_count++;
    }
  }

  if (zero_count > 1) {
    return p;
  }

  for (int i = 0; i < n; i++) {
    if (zero_count > 0) {
      if (arr[i] == 0) {
        p[i] = prod;
      }
    } else {
      p[i] = prod / arr[i];
    }
  }
  return p;
}

int main(void) {
  int arr[] = {1, 2, 4, 6};
  int *p = prod(arr, 4);
  for (int i = 0; i < 4; i++) {
    printf("%d ", p[i]);
  }
  free(p);
  return 0;
}
