
#include <algorithm>
#include <iostream>
#include <vector>
class Solution {
public:
  int min_eating_speed(std::vector<int> &piles, int h) {
    int l = 1;
    int r = *std::max_element(piles.begin(), piles.end());
    int res;
  }
};

int main(void) {
  Solution s;
  std::vector<int> piles = {30, 11, 23, 4, 20};
  std::cout << s.min_eating_speed(piles, 5) << "\n";
  return 0;
}
