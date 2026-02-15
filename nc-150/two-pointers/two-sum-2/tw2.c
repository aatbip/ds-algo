/*Given an array of integers numbers that is sorted in non-decreasing order. Return the indices (1-indexed)
 * of two numbers, [index1, index2], such that they add up to a given target number target and index1 < index2.
 * Note that index1 and index2 cannot be equal, therefore you may not use the same element twice.
 *
 * There will always be exactly one valid solution.
 * Example- Input: numbers = [1,2,3,4], target = 3
 *         Output: [1,2]
 *
 * In this program we solve the problem using two pointers approach. Since the array is already sorted, two pointers
 * method is the most optimal method to solving this problem compared to solutions using hash map and binary search.
 *
 * Time complexity- O(n)
 * Space complexity- O(1)
 */

#include <stdio.h>
#include <stdlib.h>

int *two_sum(int *arr, int n, int target) {
  int l = 0, h = n - 1;
  int *res = malloc(sizeof(int) * 2);
  while (l <= h) {
    int temp = arr[l] + arr[h];
    if (temp == target) {
      res[0] = l + 1;
      res[1] = h + 1;
      return res;
    }
    if (temp < target)
      l++;
    if (temp > target) {
      h--;
    }
  }
  return NULL;
}

int main(void) {
  int arr[] = {1, 2, 3, 4};
  int *res = two_sum(arr, 4, 7);
  printf("%d %d\n", res[0], res[1]);
  free(res);
  return 0;
}
