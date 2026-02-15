/*Given an array of integers numbers that is sorted in non-decreasing order. Return the indices (1-indexed)
 * of two numbers, [index1, index2], such that they add up to a given target number target and index1 < index2.
 * Note that index1 and index2 cannot be equal, therefore you may not use the same element twice.
 *
 * There will always be exactly one valid solution.
 * Example- Input: numbers = [1,2,3,4], target = 3
 *         Output: [1,2]
 *
 * */

#include <stdio.h>
#include <stdlib.h>

int binary_search(int *arr, int n, int key) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (key == arr[mid])
      return mid;
    if (key > arr[mid]) {
      low = mid + 1;
    }
    if (key < arr[mid]) {
      high = mid - 1;
    }
  }
  return -1;
}

int *two_sum(int *arr, int n, int target) {
  int *res = malloc(sizeof(int) * 2);
  for (int i = 0; i < n; i++) {
    int temp = target - arr[i];
    int k = binary_search(arr, n, temp);
    if (k != -1) {
      res[0] = k < i ? k + 1 : i + 1;
      res[1] = k > i ? k + 1 : i + 1;
      return res;
    }
  }
  return NULL;
}

int main(void) {
  int arr[] = {2, 4, 5, 6, 8, 9, 11, 13};
  int *res = two_sum(arr, 8, 13);
  printf("%d %d\n", res[0], res[1]);
  return 0;
}
