/*You are given a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:
 * 1. Each row must contain the digits 1-9 without duplicates.
 * 2. Each column must contain the digits 1-9 without duplicates.
 * 3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.
 * Return true if the Sudoku board is valid, otherwise return false
 * Note: A board does not need to be full or be solvable to be valid.
 *
 * This program solves the problem using bitmap and bitmask technique. We create 3 arrays that acts as
 * bitmaps where individual bits represent the number in the rows, cols or box in the sudoku. For ex,
 * rows[9] can be visualized in memory bits as follows:
 * { 0 0 0 0 0 0 0 0 0 }
 * Each element in the above array is a integer of size 4 bytes i.e. 16 bits so in the memory it looks like this:
 * 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 -> 0th element
 * 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 -> 1st element
 * 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 -> 2nd element
 * ...
 * ...
 * ...
 * 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ->  8th element
 *
 * We use bitmasking to manipulate individual bits of the above bitmap in memory.
 *
 * Time complexity- O(n^2)
 * Space complexity-
 * Since the size of Sudoku is 9x9, space complexity can actually be O(1) but assuming that size of sudoku is nxn,
 * O(n) is the space complexity.
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isValidSudoku(char (*board)[9], int n) {
  int *rows = malloc(sizeof(int) * n);
  memset(rows, 0, sizeof(*rows) * n);
  int *cols = malloc(sizeof(int) * n);
  memset(cols, 0, sizeof(*cols) * n);
  int *box = malloc(sizeof(int) * n);
  memset(box, 0, sizeof(*box) * n);

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
