/* Given an array of integers `nums` and an integer `target`, return the indices i and j such that `nums[i] + nums[j] ==
 * target` and `i != j`. You may assume that every input has exactly one Pair of indices i and j that satisfy the
 * condition. Return the answer with the smaller index first.
 *
 * In this program we will be using sorting and two pointer to solve the two sum problem.
 * Time complexity - O(nlogn)
 * Space complexity - O(n), because the size of `c_arr` grows with the size of input `arr`
 */

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> two_sum(vector<int> &arr, int target) {
    vector<pair<int, int>> c_arr;
    for (int i = 0; i < arr.size(); i++) {
      c_arr.push_back({arr[i], i});
    }
    sort(c_arr.begin(), c_arr.end());
    int low = 0, high = c_arr.size() - 1;
    while (low < high) {
      if (c_arr[low].first + c_arr[high].first == target) {
        return {min(c_arr[low].second, c_arr[high].second), max(c_arr[low].second, c_arr[high].second)};
      } else if (c_arr[low].first + c_arr[high].first < target) {
        low++;
      } else {
        high--;
      }
    }
    return {};
  }
};

int main(void) {
  Solution s;
  vector<int> arr = {6, 2, 8, 4, 7};
  vector<int> p = s.two_sum(arr, 9);
  cout << p[0] << " " << p[1] << "\n";
  return 0;
}
