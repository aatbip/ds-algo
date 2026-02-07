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
