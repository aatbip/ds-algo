/*You are given a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:
 * 1. Each row must contain the digits 1-9 without duplicates.
 * 2. Each column must contain the digits 1-9 without duplicates.
 * 3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.
 * Return true if the Sudoku board is valid, otherwise return false
 * Note: A board does not need to be full or be solvable to be valid.
 *
 * In this program we solve the problem using hash map (unordered_map) in one pass.
 * Time complexity- O(n^2)
 * Space complexity- O(n^2)
 *
 * */

#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int isValidSudoku(vector<vector<char>> &board) {
    unordered_map<int, unordered_set<char>> row, col;
    map<pair<int, int>, unordered_set<char>> box;
    for (int r = 0; r < 9; r++) {
      for (int c = 0; c < 9; c++) {
        if (board[r][c] == '.')
          continue;
        pair<int, int> box_key = {r / 3, c / 3};
        if (row[r].count(board[r][c]) || col[c].count(board[r][c]) || box[box_key].count(board[r][c])) {
          return false;
        }
        row[r].insert(board[r][c]);
        col[c].insert(board[r][c]);
        box[box_key].insert(board[r][c]);
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
}
