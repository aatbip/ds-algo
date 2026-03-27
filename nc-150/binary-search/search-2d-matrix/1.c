#include <stdbool.h>
#include <stdio.h>

int search_2d_matrix(int (*matrix)[2], int col_size, int row_size, int target) {
  for (int i = 0; i < col_size; i++) {
    if (matrix[i][row_size - 1] < target) {
      continue;
    } else {
    }
  }
  return false;
}

int main(void) {
  // int matrix[3][4] = {{1, 2, 4, 8}, {10, 11, 12, 13}, {14, 20, 30, 40}};
  int matrix[1][2] = {{1, 3}};
  printf("%d\n", search_2d_matrix(matrix, 1, 2, 2));
  return 0;
}
