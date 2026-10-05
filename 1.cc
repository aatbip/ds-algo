#include <climits>
#include <vector>

class Solution {
  int sum = INT_MIN;
  std::vector<int> vec;

  void bt(int n, int k) {}

public:
  int max_product(int n) {
    bt(n, 1);
    return sum;
  }
};
