/* 343. Integer Break -
 * Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the
 * product of those integers. Return the maximum product you can get.
 *
 * Solution-
 * This problem can be solved better optimized by using dynamic programming. We will try it soon.
 */

#include <algorithm>
#include <climits>
#include <iostream>

class Solution {
  int recurs(int n) {
    int res = 0;

    for (int i = 1; i < n; i++) {
      res = std::max(res, i * std::max(n - i, recurs(n - i))); // break n by i
    }

    return res;
  }

public:
  int integer_break(int n) { return recurs(n); }
};

int main(void) {
  Solution s;
  std::cout << s.integer_break(5) << "\n";
}
