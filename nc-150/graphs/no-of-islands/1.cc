#include <cstring>
#include <iostream>
#include <vector>
class Solution {
  void dfs(std::vector<std::vector<char>> &grid, int ROWS, int COLS) {
    if (ROWS > grid.size() || COLS > grid[0].size() || grid[ROWS][COLS] == '0')
      return;
    grid[ROWS][COLS] = '0';
    dfs(grid, ROWS + 1, COLS);
    dfs(grid, ROWS - 1, COLS);
    dfs(grid, ROWS, COLS + 1);
    dfs(grid, ROWS, COLS - 1);
  }

public:
  int no_of_islands(std::vector<std::vector<char>> &grid) {
    int count = 0;
    int ROWS = grid.size();
    int COLS = grid[0].size();
    for (int i = 0; i < ROWS; i++) {
      for (int i = 0; i < COLS; i++) {
        if (grid[ROWS][COLS] == '1') {
          count++;
          dfs(grid, ROWS, COLS);
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

  std::cout << s.no_of_islands(grid);
  return 0;
}
