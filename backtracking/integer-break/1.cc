/* 343. Integer Break -
 * Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the
 * product of those integers. Return the maximum product you can get.
 *
 * Solution-
 * Solved using backtracking. This is a brute force solution since backtracking is not optimal for more or less n > 70
 * depending on the memory available.
 *
 *
 * */

#include <climits>
#include <iostream>
#include <vector>

class Solution {
  int res = INT_MIN;
  std::vector<int> vec;

  void bt(int n, int start, int add, int mul) {
    for (int j = start; j < n; j++) {
      vec.push_back(j);
      int nadd = add + j;
      int nmul = mul * j;
      if (nadd > n) {
        vec.pop_back();
        return;
      }
      if (nadd == n && nmul > res) {
        res = nmul;
      }
      bt(n, j, nadd, nmul);
    }
  }

public:
  int max_product(int n) {
    bt(n, 1, 0, 1);
    return res;
  }
};

int main(void) {
  Solution s;
  std::cout << s.max_product(70) << "\n";
  return 0;
}
