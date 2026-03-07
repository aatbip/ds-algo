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
 * */

#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> max_window(vector<int> &nums, int k) {
    priority_queue<pair<int, int>> maxHeap;
    for (int i = 0; i < nums.size(); i++) {
      maxHeap.push({nums[i], i});
      vector<int> res;
    }
  }
};

int main(void) {
  vector<int> nums = {1, 2, 1, 0, 4, 2, 6};
  return 0;
}
