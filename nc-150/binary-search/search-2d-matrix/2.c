/*You are given an m x n 2-D integer array matrix and an integer target.
 * -> Each row in matrix is sorted in non-decreasing order.
 * -> The first integer of every row is greater than the last integer of the previous row.
 * Return `true` if target exists within matrix or `false` otherwise.
 *
 * Can you write a solution that runs in `O(log(m * n))` time?
 *
 * In this solution, we use binary search direclty with the 2d matrix knowing the fact that
 * the 2d matrix itself consists of sorted arrays. This fact makes it possible to implement
 * binary search directly on the 2d matrix.
 *
 * Time complexity - O(log m) + O(log n) = O(log(m*n)), because we are combining the entire 2d
 * matrix i.e. high = row_size * col_size - 1
 *
 * Space complexity - O(1)
 */

#include <stdbool.h>
#include <stdio.h>

int binary_search_2d_matrix(int (*matrix)[4], int row_size, int col_size, int target) {
  int low = 0, high = row_size * col_size - 1;
  for (;;) {
    if (low > high)
      break;
    int mid = (low + high) / 2;
    if (matrix[mid / col_size][mid % col_size] == target) {
      return true;
    }
    if (matrix[mid / col_size][mid % col_size] > target) {
      high = mid - 1;
    }
    if (matrix[mid / col_size][mid % col_size] < target) {
      low = mid + 1;
    }
  }
  return -1;
}

int main(void) {
  int matrix[3][4] = {{1, 2, 4, 8}, {10, 11, 12, 13}, {14, 20, 30, 40}};
  printf("%d\n", binary_search_2d_matrix(matrix, 3, 4, 8));
}
