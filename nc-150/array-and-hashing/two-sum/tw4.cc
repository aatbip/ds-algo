/* Given an array of integers `nums` and an integer `target`, return the indices i and j such that `nums[i] + nums[j] ==
 * target` and `i != j`. You may assume that every input has exactly one Pair of indices i and j that satisfy the
 * condition. Return the answer with the smaller index first.
 *
 * This program cleaverly utilizes hash map again to solve the two sum problem. This hash map based solution
 * is called "one pass" solution because we have to iterate through the array only once unlike with two pass.
 * Time complexity - O(n)
 * Space complexity - O(n), because unordered_map `s` grows with input `arr`
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> two_sum(vector<int> &arr, int target) {
    unordered_map<int, int> s;
    for (int i = 0; i < arr.size(); i++) {
      int diff = target - arr[i];
      if (s.find(diff) != s.end()) {
        return {s[diff], i};
      }
      s.insert({arr[i], i});
    }
    return {};
  }
};

int main(void) {
  Solution s;
  vector<int> arr = {1, 2, 3, 3, 5};
  vector<int> res = s.two_sum(arr, 8);
  if (!res.empty()) {
    cout << res[0] << " " << res[1] << "\n";
  }
  return 0;
}
