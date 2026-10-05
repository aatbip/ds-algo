#include <climits>
#include <iostream>
#include <vector>

class Solution {
  int res = INT_MIN;
  std::vector<int> vec;

  void bt(int n, int start, int add, int mul) {
    for (int j = start; j < n; j++) {
      vec.push_back(j);
      add += j;
      mul *= j;
      if (add > n) {
        vec.pop_back();
        return;
      }
      if (add == n && mul > res) {
        res = mul;
      }
      bt(n, j + 1, add, mul);
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
  std::cout << s.max_product(10) << "\n";
  return 0;
}
