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
#include <vector>

class Solution {
  std::vector<int> cache;

  int recurs(int n) {
    int res = 0;

    for (int i = 1; i < n; i++) {
      res = std::max(res, i * std::max(n - i, recurs(n - i))); // break n by i
    }

    return res;
  }

  int recurs_memoization(int n) {
    int res = 0;
    if (cache[n] != -1)
      return cache[n];

    for (int i = 1; i < n; i++) {
      cache[n] = std::max(cache[n], i * std::max(n - i, recurs(n - i))); // break n by i
    }

    return cache[n];
  }

public:
  int integer_break(int n) {
    cache.resize(n + 1, -1);
    return recurs_memoization(n);
  }
};

int main(void) {
  Solution s;
  std::cout << s.integer_break(5) << "\n";
}
