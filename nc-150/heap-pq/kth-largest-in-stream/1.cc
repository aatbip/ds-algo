#include <functional>
#include <iostream>
#include <queue>
#include <vector>
class KthLargest {
  int k;
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

public:
  KthLargest(int k, std::vector<int> &nums) {
    //
    this->k = k;
    for (int &n : nums) {
      min_heap.push(n);
    }
  }

  int add(int val) {
    min_heap.push(val);
    for (int i = 0; i <= min_heap.size() - k; i++) {
      min_heap.pop();
    }
    return min_heap.top();
  }
};

int main(void) {
  std::vector<int> r;
  KthLargest *sol = new KthLargest(3, r);
  std::cout << sol->add(3) << "\n";
  // sol->add(4);

  return 0;
}
