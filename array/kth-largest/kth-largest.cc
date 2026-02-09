/*Given an integer array nums and an integer k, return the kth largest element in the array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * Ex: Input: nums = [3,2,1,5,6,4], k = 2
 *     Output: 5
 *
 * Here, we solve this problem using priority queue.
 * */

#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int kth_largest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int i = 0; i < nums.size(); i++) {
      min_heap.push(nums[i]);
      if (min_heap.size() > k) {
        min_heap.pop();
      }
    }
    return min_heap.top();
  }
};

int main(void) { return 0; }
