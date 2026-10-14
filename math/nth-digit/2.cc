/*400. Nth Digit-
 *Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].
 *
 * Solution-
 * Solved using math (group skipping).
 *
 * Time complexity- O(log n)
 * Space complexity- O(1)
 * */

#include <iostream>
#include <string>
class Solution {
public:
  int find_nth_digit(int n) {
    int a = 1;
    int b = 9;
    int len = 1;

    while (n > len * b) {
      n -= len * b;
      a *= 10;
      b *= 10;
      len += 1;
    }

    int num = a + (n - 1) / len;
    std::string str = std::to_string(num);

    return str[(n - 1) % len] - '0';
  }
};

int main(void) {
  Solution s;

  std::cout << s.find_nth_digit(100000000) << "\n";

  return 0;
}
