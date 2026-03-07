/*You are given an array of integers nums and an integer k. There is a sliding window of size k that
 * starts at the left edge of the array. The window slides one position to the right until it reaches
 * the right edge of the array.
 * Return a list that contains the maximum element in the window at each step.
 *
 * Example: Input: nums = [1,2,1,0,4,2,6], k = 3
 *          Output: [2,2,4,4,6]
 *
 *          Explanation:
 *                      Window position            Max
 *                      ---------------           -----
 *                      [1  2  1] 0  4  2  6       2
 *                      1 [2  1  0] 4  2  6        2
 *                      1  2 [1  0  4] 2  6        4
 *                      1  2  1 [0  4  2] 6        4
 *                      1  2  1  0 [4  2  6]       6
 *
 * This program solves the problem using priority queue (max heap). Max heap is choosen instead of the min heap
 * because max heap stores elements with high priority as parents. We can simply use top() to check for the element
 * with highest priority.
 * */

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> max_window(vector<int> &nums, int k) {
    priority_queue<pair<int, int>> maxHeap;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      maxHeap.push({nums[i], i});
      if (i >= k - 1) {
        while (maxHeap.top().second <= i - k) {
          maxHeap.pop();
        }
        res.push_back(maxHeap.top().first);
      }
    }
    return res;
  }
};

int main(void) {
  Solution s;
  vector<int> nums = {1, 2, 1, 0, 4, 2, 6};
  vector<int> res = s.max_window(nums, 3);
  for (int el : res) {
    cout << el << " ";
  }
  return 0;
}
