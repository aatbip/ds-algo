/*400. Nth Digit-
 *Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].
 *
 * Solution-
 * Solved using stack and brute force method. The loop should iterate upto 'n' which makes this solution slow for larger
 * values of 'n'. Can be optimized better using the group skipping math approach as written in 2.cc program.
 *
 * Time complexity- O(n)
 * Space complexity- O(d), where d->digits of the current number
 * */

#include <climits>
#include <iostream>
#include <stack>

class Solution {
public:
  int find_nth_digit(int n) {
    int ans;
    int i = 1;
    int c = 0;
    while (c != n) {
      std::stack<int> s_tmp;
      int x = i;
      while (x > 0) {
        int d = x % 10;
        x = x / 10;
        s_tmp.push(d);
      }
      while (!s_tmp.empty()) {
        ans = s_tmp.top();
        c++;
        if (c >= n)
          break;
        s_tmp.pop();
      }
      i++;
    }
    return ans;
  }
};

int main(void) {
  Solution s;

  std::cout << s.find_nth_digit(100000000) << "\n";

  return 0;
}
