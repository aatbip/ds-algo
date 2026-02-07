/* Given an integer array `nums` and an integer k, return the k most frequent elements within the array. Ex:
 * Input: nums = [1,2,2,3,3,3], k = 2
 * Output: [2,3]
 *
 * In this program we solve this problem using  min-heap (priority queue based data structure) and hash map.
 * Min-heap is a good choice to track object based on their priority which in our case is the frequency
 * of how many times a number is present in the array `nums`.
 * Note: min-heap: children >= parent i.e. higher priority objects are children
 *       max-heap: parent >= children i.e. higher priority objects are parents
 * We use min-heap instead of max-heap so that we can easily pop() the objects beyond 'k' because min-heap
 * arranges the objects with higher priority (in this case, objects having higher frequency count) as
 * children so that pop() will remove the objects with lower frequency count first.
 *
 * Time complexity -
 * Let 'n' be the size of `nums`, and `k` be the requested top frequency count and 'u' be the unique
 * elements in `nums`. Then,
 *
 *   for (auto num : nums) {
 *     m[num]++;
 *   }
 *
 * The above loop has O(n) time complexity.
 *
 *   for (auto el : m) {
 *     pq.push({el.second, el.first});
 *     if (pq.size() > k) {
 *       pq.pop();
 *     }
 *   }
 *
 * Now in the above loop, the loop runs for 'u' times because there are 'u' unique elements and
 * so the size of the hash map 'm' will be of 'u' length. Also, `push` and `pop` methods of the
 * priority queue has time complexity of O(log k) because heap is not more than 'k'. So the
 * time complexity of the above loop is: O(u logk) = O(n logk) in the worst case.
 *
    for (int i = 0; i < k; i++) {
      res.push_back(pq.top().second);
      pq.pop();
    }
 *
 * Now finally the above loop have `pop` which is O(log k) and it runs for 'k' times so
 * time complexity of this loop is O(k logk).
 *
 * Now the total time complexity is =
 * O(n) + O(nlogn) + O(klogk)
 * Worst case is dominated by O(nlogn).
 * Therefore, time complexity is O(nlogn).
 *
 * */

#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> top_freq(vector<int> nums, int k) {
    unordered_map<int, int> m;
    for (auto num : nums) {
      m[num]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto el : m) {
      pq.push({el.second, el.first});
      if (pq.size() > k) {
        pq.pop();
      }
    }
    vector<int> res;
    for (int i = 0; i < k; i++) {
      res.push_back(pq.top().second);
      pq.pop();
    }
    return res;
  }
};

int main(void) {
  Solution s;
  vector<int> nums = {1, 3, 2, 3, 2, 3, 1, 1, 1};
  vector<int> res = s.top_freq(nums, 2);
  for (auto el : res) {
    cout << el << " ";
  }

  return 0;
}
