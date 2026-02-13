/*You are given a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:
 * 1. Each row must contain the digits 1-9 without duplicates.
 * 2. Each column must contain the digits 1-9 without duplicates.
 * 3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.
 * Return true if the Sudoku board is valid, otherwise return false
 * Note: A board does not need to be full or be solvable to be valid.
 *
 * */

int isValidSudoku(char (*board)[], int n) { return 1; }

int main(void) {
  char board[][9] = {{'1', '2', '.', '.', '3', '.', '.', '.', '.'}, {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
                     {'.', '9', '8', '.', '.', '.', '.', '.', '3'}, {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
                     {'.', '.', '.', '8', '.', '3', '.', '.', '5'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                     {'.', '.', '.', '.', '.', '.', '2', '.', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
                     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  isValidSudoku(board, 9);

  return 0;
}
