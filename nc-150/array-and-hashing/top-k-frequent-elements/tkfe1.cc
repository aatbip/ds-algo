/* Given an integer array `nums` and an integer k, return the k most frequent elements within the array. Ex:
 * Input: nums = [1,2,2,3,3,3], k = 2
 * Output: [2,3]
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
