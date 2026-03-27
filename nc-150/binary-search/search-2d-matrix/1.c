/*You are given an m x n 2-D integer array matrix and an integer target.
 * -> Each row in matrix is sorted in non-decreasing order.
 * -> The first integer of every row is greater than the last integer of the previous row.
 * Return `true` if target exists within matrix or `false` otherwise.
 *
 * Can you write a solution that runs in `O(log(m * n))` time?
 *
 * This solution solves the problem but in O(mlogn) time. It loops through the row to find the
 * required row then does a binary search on that row. So the iteration through the total row
 * 'm' takes O(m) time and the binary search within the row takes O(logn) time, size column size is 'n' and
 * binary search is performed only once for the required row. so,
 * total O(m) + O(logn) = O(m+logn)
 *
 * It has O(1) space complexity.
 * */

#include <stdbool.h>
#include <stdio.h>

int binary_search(int *arr, int n, int target) {
  int low = 0, high = n - 1;
  for (;;) {
    if (low > high)
      break;
    int mid = (low + high) / 2;
    if (arr[mid] == target) {
      return mid;
    }
    if (arr[mid] < target) {
      low = mid + 1;
    }
    if (arr[mid] > target) {
      high = mid - 1;
    }
  }
  return -1;
}

int search_2d_matrix(int (*matrix)[4], int col_size, int row_size, int target) {
  for (int i = 0; i < row_size; i++) {
    if (matrix[i][col_size - 1] < target) {
      continue;
    } else {
      int res = binary_search(matrix[i], col_size, target);
      if (res == -1)
        return false;
      return true;
    }
  }
  return false;
}

int main(void) {
  int matrix[3][4] = {{1, 2, 4, 8}, {10, 11, 12, 13}, {14, 20, 30, 40}};
  printf("%d\n", search_2d_matrix(matrix, 4, 3, 13));
  return 0;
}
