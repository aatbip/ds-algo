/* You are given an array of integers nums containing n + 1 integers. Each integer in nums is in the range [1, n]
 * inclusive. There is exactly one repeated integer in nums, and every other integer appears at most once. Return the
 * repeated integer.
 *
 * Solution: Solved using Floyd's cycle detection algorithm.
 * Step 1- Find if the cycle exist. To do this, point both slow and fast pointers to the head and move slow 1 step while
 * fast 2 steps. If they both meet at one node then the cycle exist.
 *
 * Step 2- Find the starting point of the cycle. Now point slow pointer to the head again while fast pointer starts from
 * the position where it was in the step 1. Move both slow and fast pointers in the same speed. The point where they
 * meet again is the starting point of the cycle.
 *
 * Time complexity- O(n)
 * Space complexity- O(1)
 * */

#include <iostream>
#include <vector>

class Solution {
public:
  int findDuplicate(std::vector<int> &nums) {
    int slow = 0;
    int fast = 0;
    for (;;) {
      slow = nums[slow];
      fast = nums[nums[fast]];
      if (slow == fast) {
        break;
      }
    }

    int slow2 = 0;
    for (;;) {
      slow = nums[slow];
      slow2 = nums[slow2];
      if (slow == slow2) {
        return slow;
      }
    }
  }
};

int main(void) {
  std::vector<int> nums = {3, 1, 3, 4, 2};
  Solution s;
  std::cout << s.findDuplicate(nums) << "\n";
  return 0;
}
