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
