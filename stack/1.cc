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
