/*You are given a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:
 * 1. Each row must contain the digits 1-9 without duplicates.
 * 2. Each column must contain the digits 1-9 without duplicates.
 * 3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.
 * Return true if the Sudoku board is valid, otherwise return false
 * Note: A board does not need to be full or be solvable to be valid.
 *
 * In this program we check if the sudoku is valid using a hash set (unordered_set) in a brute force approach.
 *
 * Time complexity- O(n^2)
 * Space complexity- O(n)
 *
 * */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int isValidSudoku(vector<vector<char>> &board) {
    for (int row = 0; row < 9; row++) {
      unordered_set<char> seen;
      for (int j = 0; j < 9; j++) {
        if (board[row][j] == '.')
          continue;
        if (seen.count(board[row][j]))
          return false;
        seen.insert(board[row][j]);
      }
    }

    for (int column = 0; column < 9; column++) {
      unordered_set<char> seen;
      for (int j = 0; j < 9; j++) {
        if (board[j][column] == '.')
          continue;
        if (seen.count(board[j][column]))
          return false;
        seen.insert(board[j][column]);
      }
    }

    for (int box = 0; box < 9; box++) {
      unordered_set<char> seen;
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (board[i][j] == '.')
            continue;
          if (seen.count(board[i][j]))
            return false;
          seen.insert(board[i][j]);
        }
      }
    }
    return true;
  }
};

int main(void) {
  vector<vector<char>> board = {
      {'1', '2', '.', '.', '3', '.', '.', '.', '.'}, {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '.', '3'}, {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
      {'.', '.', '.', '8', '.', '3', '.', '.', '5'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '.', '.', '.', '.', '.', '2', '.', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  Solution s;
  cout << s.isValidSudoku(board) << "\n";
};
