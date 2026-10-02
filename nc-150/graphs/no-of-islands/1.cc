#include <cstring>
#include <vector>
class Solution {
  void dfs(std::vector<std::vector<char *>> &grid, int ROWS, int COLS) {
    if (ROWS > grid.size() || COLS > grid[0].size() || (std::strcmp(grid[ROWS][COLS], "0") == 0))
      return;
    std::strcpy(grid[ROWS][COLS], "0");
    dfs(grid, ROWS + 1, COLS);
    dfs(grid, ROWS - 1, COLS);
    dfs(grid, ROWS, COLS + 1);
    dfs(grid, ROWS, COLS - 1);
  }

public:
  int no_of_islands(std::vector<std::vector<char *>> &grid) {
    int count = 0;
    int ROWS = grid.size();
    int COLS = grid[0].size();
    for (int i = 0; i < ROWS; i++) {
      for (int i = 0; i < COLS; i++) {
        if (std::strcmp(grid[ROWS][COLS], "1") == 0) {
          count++;
          dfs(grid, ROWS, COLS);
        }
      }
    }
    return count;
  }
};
