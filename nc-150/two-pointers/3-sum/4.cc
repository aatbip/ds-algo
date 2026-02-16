/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] where,
 * nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.
 * The output should not contain any duplicate triplets. You may return the output and the triplets in any order.
 *
 * Example- Input: vector<int> nums = {-1,0,1,2,-1,-4}
 *          Output: {{-1,-1,2},{-1,0,1}}
 *
 * In this program we use the two pointer approach to solving the problem, but in C++. As we noticed that in C we don't
 * have data structures like vector so we needed to write our own mini dynamically resizing array, which was fun!
 * However in competitive programming/programming interviews, we can make use of vector which is readily available
 * in C++.
 *
 * Time complexity- O(n^2)
 * Space complexity-
 * O(1) or O(n) extra space depending on the sorting algorithm
 * O(m) for the output array  where 'm' is the total number of triplets
 */

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> three_sum(vector<int> nums) { sort(nums.begin(), nums.end()); }
};
