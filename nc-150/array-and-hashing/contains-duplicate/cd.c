/* Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.
 *
 * The following C code solves this problem using brute force approach. With this approach,
 * time complexity - O(N^2)
 * space complexity - O(1)
 */

#include <stdio.h>
// int contains_duplicate(int *arr, int n) {
//   for (int *i = arr; i < arr + n; i++) {
//     for (int *j = i + 1; j < arr + n; j++) {
//       if (*i == *j) {
//         return 1;
//       }
//     }
//   }
//   return 0;
// }

int contains_duplicate(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] == arr[j]) {
        return 1;
      }
    }
  }
  return 0;
}

int main(void) {
  int arr[] = {1, 2, 3, 9, 0, 10, 11, 15, 8, 99, 6, 1};
  printf("%d\n", contains_duplicate(arr, sizeof(arr) / sizeof(arr[0])));
  return 0;
}
