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
};
