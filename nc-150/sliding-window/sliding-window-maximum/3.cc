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
 *
 * This program solves the problem using sliding window technique with the help of double ended queue (deque) data
 * structure.
 *
 * Time complexity - O(n)
 * Space complexity - O(k) for deque and O(n-k+1) for res array. So, O(k + n - k + 1) = O(n + 1) = O(n) in
 * asymptotic analysis
 * Deque is O(k) because it stores 'k' elements max at a time.
 */

#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> max_window(vector<int> &nums, int k) {
    vector<int> res(nums.size() - k + 1);
    int l = 0, r = 0;
    deque<int> dq;
    while (r < nums.size()) {
      while (!dq.empty() && nums[dq.back()] < nums[r]) {
        dq.pop_back();
      }
      dq.push_back(r);
      if (l > dq.front()) {
        dq.pop_front();
      }
      if (r + 1 >= k) {
        res[l] = nums[dq.front()];
        l++;
      }
      r++;
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
