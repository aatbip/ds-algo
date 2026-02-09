/*Given an integer array nums and an integer k, return the kth largest element in the array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * Ex: Input: nums = [3,2,1,5,6,4], k = 2
 *     Output: 5
 *
 * Here, we solve this problem using priority queue (min-heap).
 * Time complexity-
 * Let 'n' be the size of array and 'k' be the required largest position then,
 * the first loop is O(n)
 * the operations of priority_queue `push` and `pop` is O(logk) because heap size never exceeds 'k'.
 * Therefore, O(nlogk) is the worst case time complexity.
 *
 * Space complexity-
 * Priority queue has O(k) space complexity, therefore, O(k) is the total space complexity.
 * */

#include <functional>
#include <iostream>
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

int main(void) {
  Solution s;
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  cout << s.kth_largest(nums, 2) << "\n";
  return 0;
}
