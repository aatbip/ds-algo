#include <cstring>
#include <iostream>
#include <vector>
class Solution {
  void dfs(std::vector<std::vector<char>> &grid, int ROWS, int COLS, int r, int c) {
    if (r < 0 || c < 0 || r > grid.size() - 1 || c > grid[0].size() - 1 || grid[r][c] == '0')
      return;
    grid[r][c] = '0';
    dfs(grid, ROWS, COLS, r + 1, c);
    dfs(grid, ROWS, COLS, r - 1, c);
    dfs(grid, ROWS, COLS, r, c + 1);
    dfs(grid, ROWS, COLS, r, c - 1);
  }

public:
  int no_of_islands(std::vector<std::vector<char>> &grid) {
    int count = 0;
    int ROWS = grid.size();
    int COLS = grid[0].size();
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        if (grid[i][j] == '1') {
          count++;
          dfs(grid, ROWS, COLS, i, j);
        }
      }
    }
    return count;
  }
};

int main(void) {
  Solution s;
  std::vector<std::vector<char>> grid = {
      {'0', '1', '1', '1', '0'}, {'0', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};

  std::cout << s.no_of_islands(grid) << "\n";
  return 0;
}
