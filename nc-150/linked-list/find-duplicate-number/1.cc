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
