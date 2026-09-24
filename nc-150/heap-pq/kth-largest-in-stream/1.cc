/*Kth Largest Element In a Stream-
 *
 * Solution: Solved using min heap. Pop element from the min heap if size of the min heap exceeds 'k'. The top most
 * element is always maintained as the kth largest. Use max heap for kth smallest.
 *
 * */

#include <functional>
#include <iostream>
#include <queue>
#include <vector>

class KthLargest {
  int k;
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

public:
  KthLargest(int k, std::vector<int> &nums) {
    this->k = k;
    for (int &n : nums) {
      min_heap.push(n);
      if (min_heap.size() > k) {
        min_heap.pop();
      }
    }
  }

  int add(int val) {
    min_heap.push(val);
    if (min_heap.size() > k) {
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
