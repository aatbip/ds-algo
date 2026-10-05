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
  std::cout << s.max_product(10) << "\n";
  return 0;
}
