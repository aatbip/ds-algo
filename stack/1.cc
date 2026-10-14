#include <climits>
#include <iostream>
#include <stack>

class Solution {
public:
  int find_nth_digit(int n) {
    std::stack<int> s;
    int i = 1;
    while (s.size() != n) {
      std::stack<int> s_tmp;
      int x = i;
      while (x > 0) {
        int d = x % 10;
        x = x / 10;
        s_tmp.push(d);
      }
      while (!s_tmp.empty()) {
        s.push(s_tmp.top());
        if (s.size() >= n)
          break;
        s_tmp.pop();
      }
      i++;
    }
    return s.top();
  }
};

int main(void) {
  Solution s;

  std::cout << s.find_nth_digit(10) << "\n";

  return 0;
}
