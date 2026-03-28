/* You are given an integer array piles where piles[i] is the number of bananas
 * in the ith pile. You are also given an integer h, which represents the number
 * of hours you have to eat all the bananas.
 * You may decide your bananas-per-hour eating rate of k. Each hour, you may choose
 * a pile of bananas and eats k bananas from that pile. If the pile has less than k
 * bananas, you may finish eating the pile but you can not eat from another pile in
 * the same hour.
 * Return the minimum integer k such that you can eat all the bananas
 * within h hours.
 *
 * Example - Input: piles = [1,4,3,2], h = 9
 *           Output: 2
 *
 * This program uses binary search approach to solve the problem.
 * 'k' (eating speed) can range from 1 to 'm' where 'm' is the maximum element
 * in the array of piles. So, we first initialize 'l' (low) as 1 and 'r' (high)
 * as 'm'. Then we choose the mid (k) and then find the time taken for the mid (k).
 * Next, if (t <= h) i.e. if time taken is less than 'h' then it is the valid result.
 * We will update 'res' and then update r to k-1 (r=k-1) to check if there is another
 * valid time from between 'l' to 'k-1'. Otherwise, we will update l to k+1 (l=k+1).
 * This will help us find the result in O(logn) time using binary search.
 *
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

class Solution {
public:
  int min_eating_speed(std::vector<int> &piles, int h) {
    int l = 1;
    int r = *std::max_element(piles.begin(), piles.end());
    int res;
    while (l <= r) {
      int k = (l + r) / 2; // mid element
      long long t = 0;
      for (auto pile : piles) {
        t += std::ceil((double)pile / k);
      }
      if (t <= h) { // valid case
        res = k;
        r = k - 1;
      }
      if (t > h) {
        l = k + 1;
      }
    }
    return res;
  }
};

int main(void) {
  Solution s;
  std::vector<int> piles = {30, 11, 23, 4, 20};
  std::cout << s.min_eating_speed(piles, 5) << "\n";
  return 0;
}
