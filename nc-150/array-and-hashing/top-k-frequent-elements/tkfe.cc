/* Given an integer array `nums` and an integer k, return the k most frequent elements within the array. Ex:
 * Input: nums = [1,2,2,3,3,3], k = 2
 * Output: [2,3]
 *
 * This program solves the problem using sorting and hash map. Hash map is used to count the frequencies
 * which will be sorted by rearranging the frequencies in the vector then top k items are returned.
 * Time complexity - O(nlogn), sorting algorithm has the worst case time complexity
 * Space complexity - O(n)
 **/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> top_freq(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      m[nums[i]]++;
    }
    vector<pair<int, int>> pair;
    for (const auto &p : m) {
      pair.push_back({p.second, p.first});
    }
    sort(pair.rbegin(), pair.rend());

    vector<int> res;
    for (int i = 0; i < k; i++) {
      res.push_back(pair[i].second);
    }
    return res;
  }
};

int main(void) {
  Solution s;
  vector<int> nums = {1, 3, 2, 3, 2, 3, 1, 1};
  vector<int> res = s.top_freq(nums, 2);
  for (auto el : res) {
    cout << el << " ";
  }

  return 0;
}
