/* Given an integer array `nums` and an integer k, return the k most frequent elements within the array. Ex:
 * Input: nums = [1,2,2,3,3,3], k = 2
 * Output: [2,3]
 *
 * In this program, we solve the problem using bucket sort and hash map. We first distribute the numbers
 * according to the frequency in the buckets. Distributing elements in the buckets according to their
 * frequency is also called as distribution sort. Bucket in this case is the 2d array where each
 * sub array stores elements of frequency equivalent to the index of the sub array.
 *
 *
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> top_freq(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    for (auto num : nums) {
      m[num]++;
    }
    vector<vector<int>> freq_buckets(nums.size() + 1);
    for (auto el : m) {
      freq_buckets[el.second].push_back(el.first);
    }
    vector<int> res;
    for (int i = nums.size(); i > 0; --i) {
      for (auto n : freq_buckets[i]) {
        res.push_back(n);
        if (res.size() == k) {
          return res;
        }
      }
    }
    return res;
  }
};

int main(void) {
  Solution s;
  vector<int> nums = {1, 2, 2, 2, 2, 2, 4, 4, 5, 5, 5, 5, 5, 3, 3, 3, 3};
  vector<int> res = s.top_freq(nums, 3);
  for (auto el : res) {
    cout << el << "\n";
  }

  return 0;
}
