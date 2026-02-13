/*You are given a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:
 * 1. Each row must contain the digits 1-9 without duplicates.
 * 2. Each column must contain the digits 1-9 without duplicates.
 * 3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.
 * Return true if the Sudoku board is valid, otherwise return false
 * Note: A board does not need to be full or be solvable to be valid.
 *
 * */

#include <stdio.h>
int isValidSudoku(char (*board)[9], int n) {
  int rows[9] = {0};
  int cols[9] = {0};
  int box[9] = {0};

  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      int val = board[r][c] - '1';
      int box_idx = (r / 3) * 3 + c / 3;
      if (board[r][c] == '.')
        continue;
      if (rows[r] & (1 << val) || cols[c] & (1 << val) || box[box_idx] & (1 << val)) {
        return 0; // invalid sudoku
      }
      rows[r] |= (1 << val);
      cols[c] |= (1 << val);
      box[box_idx] |= (1 << val);
    }
  }
  return 1; // valid sudoku
}

int main(void) {
  char board[][9] = {{'1', '2', '.', '.', '3', '.', '.', '.', '.'}, {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
                     {'.', '9', '8', '.', '.', '.', '.', '.', '3'}, {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
                     {'.', '.', '.', '8', '.', '3', '.', '.', '5'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                     {'.', '.', '.', '.', '.', '.', '2', '.', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
                     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  printf("%d\n", isValidSudoku(board, 9));

  return 0;
}
